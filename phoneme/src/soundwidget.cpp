/*
 * Copyright  2012 Davy Preuveneers. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include <QDebug>
#include <QSound>
#include <QFile>

#include "soundwidget.h"

SoundWidget::SoundWidget(QWidget *parent) : QWidget(parent) {
    mMediaObject = new Phonon::MediaObject(this);
    mAudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mAudioOutput->setVolume(0.75);

    Phonon::createPath(mMediaObject, mAudioOutput);
}

void SoundWidget::setSound(QString filename) {
    mMediaObject->setCurrentSource(filename);
}

void SoundWidget::stopSound() {
    mMediaObject->stop();
}

void SoundWidget::playSound() {
    mMediaObject->play();
}

void SoundWidget::playFile(QString filename) {
    QFile file(filename);
    if (file.exists()) {
        qDebug() << "INFO: Playing" << filename;

        setSound(filename);
        mMediaObject->play();
    } else {
        qDebug() << "ERROR: File" << filename << "does not exist!";
    }
}

void SoundWidget::playAlert(int i) {
#ifdef Q_WS_MAEMO_5
    if (i == 3)
        playFile("/usr/share/sounds/ui-default_beep.wav");
    else if (i == 2)
        playFile("/usr/share/sounds/ui-general_warning.wav");
    else if (i == 1)
        playFile("/usr/share/sounds/ui-information_note.wav");
    else if (i == 5)
        playFile("/usr/share/sounds/ui-confirmation_note.wav");
    else if (i == 4)
        playFile("/usr/share/sounds/ui-operation_ready.wav");
    else
        playFile("/usr/share/sounds/ui-default_beep.wav");
#else
    if (i == 3)
        playFile("/usr/share/sounds/ui-tones/snd_default_beep.wav");
    else if (i == 2)
        playFile("/usr/share/sounds/ui-tones/snd_warning.wav");
    else if (i == 1)
        playFile("/usr/share/sounds/ui-tones/snd_information.wav");
    else if (i == 5)
        playFile("/usr/share/sounds/ui-tones/snd_query.wav");
    else if (i == 4)
        playFile("/usr/share/sounds/ui-tones/snd_warning_strong.wav");
    else
        playFile("/usr/share/sounds/ui-tones/snd_default_beep.wav");
#endif
}
