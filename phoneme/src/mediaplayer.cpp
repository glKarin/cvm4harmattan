#include "mediaplayer.h"
//#include <QMediaPlayer>

#include <QFileInfo>
#include <QUrl>
#include <QStringList>
#include <QDebug>

namespace karin
{
	MediaPlayer::MediaPlayer(QObject *parent)
		: QObject(parent),
		m_loopCount(1)
	{
		setObjectName("karin_MediaPlayer");
	}

	MediaPlayer::~MediaPlayer()
	{
	}

	int MediaPlayer::LoopCount() const
	{
		return m_loopCount;
	}

	void MediaPlayer::SetLoopCount(int c)
	{
		if(m_loopCount != c)
			m_loopCount = c;
	}
}

#ifdef _MEDIAPLAYER_BACKEND_USING_QTMOBILITY

extern "C" {
#include "wildmidi/wildmidi_lib.h"
}

namespace karin
{
#define SAMPLERATE 11250
#define BUFFER_SIZE 16384
//#define CFG_FILE "/usr/local/lib/timidity/timidity.cfg"
//#define CFG_FILE "/etc/wildmidi/wildmidi.cfg"
#define CFG_FILE "wildmidi.cfg"

	bool MidiHandler_base::_inited = false;

	MidiHandler_base::MidiHandler_base()
	{
		InitWildMidi();
	}

	MidiHandler_base::~MidiHandler_base()
	{
		//ShutdownWildMidi();
	}

	bool MidiHandler_base::IsWildMidiInit()
	{
		return _inited;
	}

	bool MidiHandler_base::Load(const QString &file)
	{
		midi *m;
		int res;
		int count;
		bool suc;

		if(!IsWildMidiInit())
			return false;

		m = WildMidi_Open(file.toStdString().c_str());
		qDebug() << "midi -> " << m;
		if(!m)
			return false;

		if(!Ready(file))
			return false;

		res = 0;
		count = 0;
		suc = true;
		char buf[BUFFER_SIZE];
		while(1)
		{
			//memset(buf, 0, sizeof(buf));
			res = WildMidi_GetOutput(m, buf, BUFFER_SIZE);
			//printf("res -> %d\n", res);
			if(res <= 0)
				break;
			count += res;
			if(!Handle(buf, res))
			{
				suc = false;
				break;
			}
		}

		if(suc)
		{
			qDebug() << "midi length -> " << count;
			if(!Finish(count))
				suc = false;
		}
		else
			Finish(-1);

		WildMidi_Close(m);

		return suc;
	}

	bool MidiHandler_base::InitWildMidi()
	{
		if(_inited)
			return true;

		const char midi_cfg[] = CFG_FILE;
		int res;

		res = WildMidi_Init(midi_cfg, SAMPLERATE, 0);
		if(res == 0)
		{
			_inited = true;
			WildMidi_MasterVolume(100);
		}

		return res == 0;
	}

	bool MidiHandler_base::ShutdownWildMidi()
	{
		if(!_inited)
			return true;
		WildMidi_Shutdown();
		return true;
	}



	MidiToWavHandler::MidiToWavHandler()
		: MidiHandler_base(),
		m_file(0)
	{
	}

	MidiToWavHandler::~MidiToWavHandler()
	{
		Shutdown();
	}

	void MidiToWavHandler::Shutdown()
	{
		if(m_file)
		{
			if(m_file->isOpen())
			{
				m_file->flush();
				m_file->close();
			}
		}
		
		delete m_file;
		m_file = 0;
	}

	bool MidiToWavHandler::IsOpen() const
	{
		return m_file && m_file->isOpen();
	}

	QString MidiToWavHandler::WavFilePath() const
	{
		return m_filePath;
	}

	bool MidiToWavHandler::Ready(const QString &file)
	{
		QFileInfo info(file);
		int len;

		if(!info.exists())
			return false;

		QString filename = info.absolutePath() + "/" + info.baseName() + "_wildmidi.wav";

		Shutdown();
		m_file = new QFile;
		m_file->setFileName(filename);
		m_file->open(QIODevice::WriteOnly);
		
		// header
		{
			char wav_hdr[] = { 0x52, 0x49, 0x46, 0x46, 0x00, 0x00, 0x00, 0x00,
				0x57, 0x41, 0x56, 0x45, 0x66, 0x6D, 0x74, 0x20,
				0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00,
				0x44, 0xAC, 0x00, 0x00, 0x10, 0xB1, 0x02, 0x00,
				0x04, 0x00, 0x10, 0x00, 0x64, 0x61, 0x74, 0x61,
				0x00, 0x00, 0x00, 0x00 };
			unsigned long int bytes_per_sec;
			int rate = SAMPLERATE;

			wav_hdr[24] = (rate) & 0xFF;
			wav_hdr[25] = (rate >> 8) & 0xFF;

			bytes_per_sec = rate * 4;
			wav_hdr[28] = (bytes_per_sec) & 0xFF;
			wav_hdr[29] = (bytes_per_sec >> 8) & 0xFF;
			wav_hdr[30] = (bytes_per_sec >> 16) & 0xFF;
			wav_hdr[31] = (bytes_per_sec >> 24) & 0xFF;

			len = m_file->write(wav_hdr, 44);
			if(len != 44)
			{
				Shutdown();
				return false;
			}
		}

		return true;
	}

	bool MidiToWavHandler::Handle(const char *data, int size)
	{
		int len;

		if(!IsOpen())
			return false;
		if(!data || size <= 0)
			return false;

		len = m_file->write(data, size);
		if(len != size)
		{
			Shutdown();
			return false;
		}
		return true;
	}

	bool MidiToWavHandler::Finish(int size)
	{
		int len;

		if(!IsOpen())
			return false;

		if(size <= 0)
		{
			Shutdown();
			return true;
		}

		{
			int wav_size = size;
			char wav_count[4];

			wav_count[0] = (wav_size) & 0xFF;
			wav_count[1] = (wav_size >> 8) & 0xFF;
			wav_count[2] = (wav_size >> 16) & 0xFF;
			wav_count[3] = (wav_size >> 24) & 0xFF;
			m_file->seek(40);
			len = m_file->write(wav_count,4);
			if(len != 4)
			{
				Shutdown();
				return false;
			}

			wav_size += 36;
			wav_count[0] = (wav_size) & 0xFF;
			wav_count[1] = (wav_size >> 8) & 0xFF;
			wav_count[2] = (wav_size >> 16) & 0xFF;
			wav_count[3] = (wav_size >> 24) & 0xFF;
			m_file->seek(4);
			len = m_file->write(wav_count,4);
			if(len != 4)
			{
				Shutdown();
				return false;
			}
		}

		m_file->flush();
		m_file->close();
		m_filePath = m_file->fileName();
		return true;
	}



	QtMobilityMediaPlayer::QtMobilityMediaPlayer(QObject *parent)
		: MediaPlayer(parent),
		m_mediaPlayer(new QMediaPlayer(this, QMediaPlayer::LowLatency))
	{
		setObjectName("karin_QtMobilityMediaPlayer");
		qRegisterMetaType<QMediaContent>("QMediaContent");
		m_mediaPlayer->setVolume(75);

		connect(m_mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(OnStateChanged(QMediaPlayer::State)));
	}

	QtMobilityMediaPlayer::~QtMobilityMediaPlayer()
	{
	}

	void QtMobilityMediaPlayer::setMedia(const QUrl &url)
	{
		m_mediaPlayer->setMedia(url);
		//k m_mediaPlayer->play();
	}

	void QtMobilityMediaPlayer::setMedia(const QString &str)
	{
		QStringList list = str.split(" ");
		if(list.size() != 2)
			return;
		QString filename = list[0];
		QString code = list[1];
		QFileInfo file(filename);
		if(!file.exists())
			return;
		QString suffix(file.suffix());
		suffix = suffix.toLower();
		if(suffix == "mid" || suffix == "midi")
		{
			MidiToWavHandler h;
			if(h.Load(filename))
				filename = h.WavFilePath();
			else
			{
				qWarning() << "[Frontend]: convert midi to wav error!";
				//return;
			}
		}

		if(m_mediaFiles.contains(code))
		{
			if(m_mediaFiles[code] != filename)
				m_mediaFiles[code] = filename;
		}
		else
		{
			m_mediaFiles[code] = filename;
		}

		qDebug() << "INFO: Playing" << filename;
		m_mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
		//k m_mediaPlayer->play(); // do not play now
	}

	void QtMobilityMediaPlayer::play(const QString &code_str)
	{
		QStringList list = code_str.split(" ");
		QString code = list.takeFirst();
		if(!m_mediaFiles.contains(code))
			return;

		QString &filename = m_mediaFiles[code];
		QFileInfo file(filename);
		QString suffix(file.suffix());
		suffix = suffix.toLower();
		if(suffix == "mid" || suffix == "midi")
		{
			MidiToWavHandler h;
			if(h.Load(filename))
				filename = h.WavFilePath();
			else
			{
				qWarning() << "[Frontend]: convert midi to wav error!";
				//return;
			}
		}

		QString loopCount = list.takeFirst();
		SetLoopCount(loopCount.toInt());
		if(m_currentMedia == code)
		{
			if(m_mediaPlayer->state() == QMediaPlayer::PlayingState)
			{
				if(m_mediaPlayer->position() >= m_mediaPlayer->duration())
				{
					m_mediaPlayer->setPosition(0);
					m_mediaPlayer->play();
				}
			}
			else if(m_mediaPlayer->state() == QMediaPlayer::StoppedState)
			{
				m_mediaPlayer->setPosition(0);
				m_mediaPlayer->play();
			}
			return; //k wait play end
		}
		m_loopPlayedCount = 0;
		m_currentMedia = code;
		m_mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
		m_mediaPlayer->play();
		qDebug() << "[Frontend]: start -> " << code << '-' << filename << ":" << m_loopCount;
	}

	void QtMobilityMediaPlayer::stop(const QString &code)
	{
		if(!m_mediaFiles.contains(code))
			return;
		m_mediaPlayer->stop();
		qDebug() << "[Frontend]: stop -> " << code;
	}

	void QtMobilityMediaPlayer::setVolume(int v)
	{
		m_mediaPlayer->setVolume(v);
	}

	void QtMobilityMediaPlayer::OnStateChanged(QMediaPlayer::State state)
	{
		switch(state)
		{
			case QMediaPlayer::PlayingState:
				break;
			case QMediaPlayer::PausedState:
				break;
			case QMediaPlayer::StoppedState:
				if(m_loopCount > 1 || m_loopCount < 0)
				{
					m_loopPlayedCount++;
					qDebug() << "[Frontend]: play loop -> " << m_loopPlayedCount << "/" << m_loopCount;
					if(m_loopCount < 0 || m_loopPlayedCount < m_loopCount)
					{
						m_mediaPlayer->setPosition(0);
						m_mediaPlayer->play();
					}
				}
				break;
			default:
				break;
		}
	}
}

#endif

#ifdef _MEDIAPLAYER_BACKEND_USING_PHONON
#include <phonon/mediaobject.h>
#include <phonon/mediasource.h>
#include <phonon/audiooutput.h>

namespace karin
{
	PhononMediaPlayer::PhononMediaPlayer(QObject *parent)
		: MediaPlayer(parent),
		m_mediaObject(new Phonon::MediaObject(this)),
		m_audioOutput(new Phonon::AudioOutput(Phonon::MusicCategory, this))
	{
		setObjectName("karin_PhononMediaPlayer");
		qRegisterMetaType<Phonon::MediaSource>("MediaSource");
		m_audioOutput->setVolume(0.75);

		Phonon::createPath(m_mediaObject, m_audioOutput);
	}

	PhononMediaPlayer::~PhononMediaPlayer()
	{
	}

	void PhononMediaPlayer::setMedia(const QUrl &url)
	{
		m_mediaObject->setCurrentSource(url);
		m_mediaObject->play();
	}

	void PhononMediaPlayer::setMedia(const QString &str)
	{
		QStringList list = str.split(" ");
		if(list.size() != 2)
			return;
		QString filename = list[0];
		QString code = list[1];
		QFileInfo file(filename);
		if(!file.exists())
			return;
		if(m_mediaFiles.contains(code))
		{
			if(m_mediaFiles[code] != filename)
				m_mediaFiles[code] = filename;
		}
		else
		{
			m_mediaFiles[code] = filename;
		}
		qDebug() << "INFO: Playing" << filename;
		m_mediaObject->setCurrentSource(filename);
		m_mediaObject->play();
	}

	void PhononMediaPlayer::play(const QString &code)
	{
		if(!m_mediaFiles.contains(code))
			return;
		m_mediaObject->setCurrentSource(m_mediaFiles[code]);
		m_mediaObject->play();
		qDebug() << "start -> " << code << ':' << m_mediaObject->errorString();
	}

	void PhononMediaPlayer::stop(const QString &code)
	{
		if(!m_mediaFiles.contains(code))
			return;
		m_mediaObject->stop();
		qDebug() << "stop -> " << code << ':' << m_mediaObject->errorString();
	}

	void PhononMediaPlayer::setVolume(int v)
	{
		m_audioOutput->setVolume((float)v / 100);
	}
}
#endif

#ifdef _MEDIAPLAYER_BACKEND_USING_SDL

namespace karin
{
	const static int freq = MIX_DEFAULT_FREQUENCY;
	const static Uint16 format = MIX_DEFAULT_FORMAT;
	const static int channel = MIX_DEFAULT_CHANNELS;
	const static int chunk_size = 512;

	bool SDLMediaPlayer::_sdlInited = false;

	SDLMediaPlayer::SDLMediaPlayer(QObject *parent)
		: MediaPlayer(parent),
		m_currentMusic(0)
	{
		setObjectName("karin_SDLMediaPlayer");
		InitSDL();
	}

	SDLMediaPlayer::~SDLMediaPlayer()
	{
		if(m_currentMusic)
		{
			SDL_HaltMusic();
			SDL_FreeMusic(m_currentMusic);
		}
		ShutdownSDL();
	}

	void SDLMediaPlayer::setMedia(const QUrl &url)
	{
		if(!IsSDLInit())
			return;
		qWarning() << "Unimpl -> " <<__func__ << url;
	}

	void SDLMediaPlayer::setMedia(const QString &str)
	{
		if(!IsSDLInit())
			return;

		QStringList list = str.split(" ");
		if(list.size() != 2)
			return;
		QString filename = list[0];
		QString code = list[1];
		QFileInfo file(filename);
		if(!file.exists())
			return;
		QString suffix(file.suffix());
		suffix = suffix.toLower();
		if(suffix == "mid" || suffix == "midi")
		{
		}

		if(m_mediaFiles.contains(code))
		{
			if(m_mediaFiles[code] != filename)
				m_mediaFiles[code] = filename;
		}
		else
		{
			m_mediaFiles[code] = filename;
		}

		qDebug() << "INFO: Playing" << filename;

		SDL_FreeMusic(m_currentMusic);
		m_currentMusic = 0;
		m_currentMusic = SDL_LoadMUS(filename);
	}

	void SDLMediaPlayer::play(const QString &code_str)
	{
		if(!IsSDLInit())
			return;

		QStringList list = code_str.split(" ");
		QString code = list.takeFirst();
		if(!m_mediaFiles.contains(code))
			return;

		QString &filename = m_mediaFiles[code];
		QFileInfo file(filename);
		QString suffix(file.suffix());
		suffix = suffix.toLower();
		if(suffix == "mid" || suffix == "midi")
		{
		}

		QString loopCount = list.takeFirst();
		SetLoopCount(loopCount.toInt());
		if(m_currentMedia == code && m_currentMusic)
		{
			//SDL_ResumeMusic();
			if(!Mix_PlayingMusic())
				SDL_PlayMusic(m_currentMusic, LoopCount());
			return;
		}
		m_currentMedia = code;
		SDL_FreeMusic(m_currentMusic);
		m_currentMusic = 0;
		m_currentMusic = SDL_LoadMUS(filename);
		if(!m_currentMusic)
			return;

		SDL_PlayMusic(m_currentMusic, LoopCount());
		qDebug() << "[Frontend]: start -> " << code << '-' << filename << ":" << m_loopCount;
	}

	void SDLMediaPlayer::stop(const QString &code)
	{
		if(!IsSDLInit())
			return;

		if(!m_mediaFiles.contains(code))
			return;
		
		SDL_HaltMusic();
		qDebug() << "[Frontend]: stop -> " << code;
	}

	void SDLMediaPlayer::setVolume(int v)
	{
		if(!IsSDLInit())
			return;

		Mix_VolumeMusic(v);
	}

	bool SDLMediaPlayer::InitSDL()
	{
		if(_sdlInited)
			return true;

		if(SDL_Init(SDL_INIT_AUDIO) != 0)
		{
			qWarning() << "SDL_Init(SDL_INIT_AUDIO)" << SDL_GetError();
			return false;
		}
		if(Mix_OpenAudio(freq, format, channel, chunk_size) != 0)
		{
			qWarning() << "Mix_OpenAudio" << Mix_GetError();
			return false;
		}
		_sdlInited = true;
		return true;
	}

	bool SDLMediaPlayer::IsSDLInit()
	{
		return _sdlInited;
	}

	bool SDLMediaPlayer::ShutdownSDL()
	{
		if(!_sdlInited)
			return false;

		Mix_CloseAudio();
		SDL_Quit();
		_sdlInited = false;

		return true;
	}

	Mix_Music * SDLMediaPlayer::SDL_LoadMUS(const QString &file) const
	{
		Mix_Music *music;

		music = Mix_LoadMUS(file.toStdString().c_str());
		if(!music)		
		{
			qWarning() << "Mix_LoadMUS -> " << Mix_GetError();
			return NULL;
		}
		return music;
	}

	bool SDLMediaPlayer::SDL_PlayMusic(Mix_Music *music, int loop) const
	{
		if(!music)
			return false;

		if(Mix_PlayingMusic())
			return true;

		if(Mix_PlayMusic(music, loop) != 0)
		{
			qDebug() << "Mix_PlayMusic -> " << Mix_GetError();
			return false;
		}
		return true;
	}

	void SDLMediaPlayer::SDL_FreeMusic(Mix_Music *music) const
	{
		if(!music)
			return;
		Mix_HaltMusic();
		Mix_FreeMusic(music);
	}

	void SDLMediaPlayer::SDL_PauseMusic(void) const
	{
		if(Mix_PlayingMusic() == 0)
			return;
		Mix_PauseMusic();
	}

	void SDLMediaPlayer::SDL_HaltMusic(void) const
	{
		Mix_HaltMusic();
	}

	void SDLMediaPlayer::SDL_ResumeMusic(void) const
	{
		Mix_RewindMusic();
		Mix_ResumeMusic();
	}

}
#endif
