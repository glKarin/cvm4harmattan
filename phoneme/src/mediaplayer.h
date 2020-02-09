#ifndef _KARIN_MEDIAPLAYER_H
#define _KARIN_MEDIAPLAYER_H

#include <QObject>
class QUrl;

namespace karin
{
	class MediaPlayer : public QObject
	{
		Q_OBJECT
		public:
			explicit MediaPlayer(QObject *parent = 0);
		virtual ~MediaPlayer();
		int LoopCount() const;

		public Q_SLOTS:
			virtual void setMedia(const QUrl &url) = 0;
			virtual void setMedia(const QString &file) = 0;
		virtual void play(const QString &code) = 0;
		virtual void stop(const QString &code) = 0;
		virtual void setVolume(int v) = 0;
		void SetLoopCount(int c);

		protected:
		int m_loopCount;

		private:
		Q_DISABLE_COPY(MediaPlayer)
	};
}

#ifdef _MEDIAPLAYER_BACKEND_USING_QTMOBILITY
#include <QHash>
#include <QMediaPlayer>

class QFile;

namespace karin
{
	class QtMobilityMediaPlayer;

	class MidiHandler_base
	{
		public:
			explicit MidiHandler_base();
			virtual ~MidiHandler_base();
			bool Inited() const;
			virtual bool Load(const QString &file);

		protected:
			virtual bool Ready(const QString &file) = 0;
			virtual bool Handle(const char *data, int size) = 0;
			virtual bool Finish(int size) = 0;

		private:
			static bool IsWildMidiInit();
			static bool InitWildMidi();
			static bool ShutdownWildMidi();

		private:
			static bool _inited;

	};

	class MidiToWavHandler : public MidiHandler_base
	{
		public:
			explicit MidiToWavHandler();
			virtual ~MidiToWavHandler();
			QString WavFilePath() const;

		protected:
			virtual bool Ready(const QString &file);
			virtual bool Handle(const char *data, int size);
			virtual bool Finish(int size = -1);

		private:
			void Shutdown();
			bool IsOpen() const;

		private:
			QString m_filePath;
			QFile *m_file;

			friend class QtMobilityMediaPlayer;
	};

	class QtMobilityMediaPlayer : public MediaPlayer
	{
		Q_OBJECT
		public:
			explicit QtMobilityMediaPlayer(QObject *parent = 0);
		virtual ~QtMobilityMediaPlayer();

		public Q_SLOTS:
			void setMedia(const QUrl &url);
		virtual void setMedia(const QString &file);
		void play(const QString &code);
		void stop(const QString &code);
		void setVolume(int v);

		private Q_SLOTS:
			void OnStateChanged(QMediaPlayer::State state);

		private:
		typedef QHash<QString, QString> MediaFile_t;
		QMediaPlayer *m_mediaPlayer;
		MediaFile_t m_mediaFiles;
		int m_loopPlayedCount;
		QString m_currentMedia;

		Q_DISABLE_COPY(QtMobilityMediaPlayer)
	};

typedef QtMobilityMediaPlayer SystemMediaPlayer;
}
#endif

#ifdef _MEDIAPLAYER_BACKEND_USING_PHONON
#include <QHash>

namespace Phonon
{
	class MediaObject;
	class AudioOutput;
};

namespace karin
{
	class PhononMediaPlayer : public MediaPlayer
	{
		Q_OBJECT
		public:
			explicit PhononMediaPlayer(QObject *parent = 0);
		virtual ~PhononMediaPlayer();

		public Q_SLOTS:
			void setMedia(const QUrl &url);
		virtual void setMedia(const QString &file);
		void play(const QString &code);
		void stop(const QString &code);
		void setVolume(int v);

		private:
		typedef QHash<QString, QString> MediaFile_t;
		Phonon::MediaObject* m_mediaObject;
		Phonon::AudioOutput* m_audioOutput;
		MediaFile_t m_mediaFiles;

		Q_DISABLE_COPY(PhononMediaPlayer)
	};

typedef PhononMediaPlayer SystemMediaPlayer;
}
#endif

#ifdef _MEDIAPLAYER_BACKEND_USING_SDL
#include <QHash>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

namespace karin
{
	class SDLMediaPlayer : public MediaPlayer
	{
		Q_OBJECT
		public:
			explicit SDLMediaPlayer(QObject *parent = 0);
		virtual ~SDLMediaPlayer();
		bool Inited() const;

		public Q_SLOTS:
			void setMedia(const QUrl &url);
		virtual void setMedia(const QString &file);
		void play(const QString &code);
		void stop(const QString &code);
		void setVolume(int v);

		private:
			static bool IsSDLInit();
			static bool InitSDL();
			static bool ShutdownSDL();
			Mix_Music * SDL_LoadMUS(const QString &file) const;
			bool SDL_PlayMusic(Mix_Music *music, int loop = -1) const;
			void SDL_FreeMusic(Mix_Music *music) const;
			void SDL_PauseMusic(void) const;
			void SDL_HaltMusic(void) const;
			void SDL_ResumeMusic(void) const;

		private:
			static bool _sdlInited;
			typedef QHash<QString, QString> MediaFile_t;
			MediaFile_t m_mediaFiles;
			QString m_currentMedia;
			Mix_Music *m_currentMusic;

		Q_DISABLE_COPY(SDLMediaPlayer)
	};

typedef SDLMediaPlayer SystemMediaPlayer;
}
#endif

#endif
