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

#include "locationwidget.h"

LocationWidget::LocationWidget(QObject *parent) : QObject(parent) {
    source = NULL;

    source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
    }
}

void LocationWidget::positionUpdated(const QGeoPositionInfo &info) {
    bool val = info.isValid();
    double lat = 0.0;
    double lon = 0.0;
    float alt = 0.0;
    float spd = 0.0;
    float brg = 0.0;
    float acc = 0.0;

    if (val) {
        lat = info.coordinate().latitude();
        lon = info.coordinate().longitude();
        alt = info.coordinate().altitude();

        if (info.hasAttribute(QGeoPositionInfo::GroundSpeed))
            spd = info.attribute(QGeoPositionInfo::GroundSpeed);
        if (info.hasAttribute(QGeoPositionInfo::Direction))
            brg = info.attribute(QGeoPositionInfo::Direction);
        if (info.hasAttribute(QGeoPositionInfo::HorizontalAccuracy))
            acc = info.attribute(QGeoPositionInfo::HorizontalAccuracy);

        update_location(val, lat, lon, alt, spd, brg, acc);
    }
}

void LocationWidget::startUpdates() {
    if (source) {
        source->startUpdates();
    }
}

void LocationWidget::stopUpdates() {
    if (source) {
        source->stopUpdates();
    }
}
