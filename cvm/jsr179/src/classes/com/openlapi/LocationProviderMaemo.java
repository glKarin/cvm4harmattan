package com.openlapi;

import java.io.*;
import java.util.*;

import java.lang.ClassNotFoundException;

import javax.microedition.io.Connector;

public class LocationProviderMaemo extends LocationProviderSimplified {

	private static native void initGpsProvider();
	private static native void finishGpsProvider();
	private static native boolean isValid();
	private static native double getLatitude();
	private static native double getLongitude();
	private static native float getAltitude();
	private static native float getSpeed();
	private static native float getBearing();
	private static native float getAccuracy();

	class MaemoLocationDaemon implements Runnable {
		private volatile boolean end = false;
		private final long interval;

		/**
		 * @param interval
		 *            in milliseconds
		 */
		MaemoLocationDaemon(long interval) {
			this.interval = interval;

			initGpsProvider();
		}

		public void end() {
			end = true;
			updateState(TEMPORARILY_UNAVAILABLE);

			finishGpsProvider();
		}

		public void run() {
			while (!end) {
				updateLocation(getMaemoLocation());
				try {
					Thread.sleep(interval);
				} catch (InterruptedException e) {
				}
			}
		}

		public String[] split(String splitStr, String delimiter) {
			StringBuffer token = new StringBuffer();
			Vector tokens = new Vector();
			// split
			char[] chars = splitStr.toCharArray();
			for (int i=0; i < chars.length; i++) {
				if (delimiter.indexOf(chars[i]) != -1) {
					// we bumbed into a delimiter
					if (token.length() > 0) {
						tokens.addElement(token.toString());
						token.setLength(0);
					}
				} else {
					token.append(chars[i]);
				}
			}
			// don't forget the "tail"...
			if (token.length() > 0) {
				tokens.addElement(token.toString());
			}
			// convert the vector into an array
			String[] splitArray = new String[tokens.size()];
			for (int i=0; i < splitArray.length; i++) {
				splitArray[i] = (String)tokens.elementAt(i);
			}
			return splitArray;
		}

		private synchronized Location getMaemoLocation() {
			long timestamp = System.currentTimeMillis();
			boolean valid = false;
			double latitude = 0.0;
			double longitude = 0.0;
			float altitude = 0.0f;
			float speed = 0.0f;
			float bearing = 0.0f;
			float accuracy = 0.0f;

			valid = isValid();
			latitude = getLatitude();
			longitude = getLongitude();
			altitude = getAltitude();
			speed = getSpeed();
			bearing = getBearing();
			accuracy = getAccuracy();

			Location location = new Location();
			location.timestamp = timestamp;
			location.valid = valid;
			location.qualifiedCoordinates = new QualifiedCoordinates(latitude, longitude, altitude, accuracy, accuracy);
			location.setSpeed(speed);
			location.setCourse(bearing);
			return location;
		}
	}

	private static volatile MaemoLocationDaemon daemon = null;

	/**
	 * @param criteria
	 * @param source
	 * @throws LocationException
	 */
	LocationProviderMaemo(Criteria criteria)
			throws LocationException {

		startBackend();
	}

	protected void startBackend() throws LocationException {
		if (daemon != null)
			return;

		long interval = 1000;
		daemon = new MaemoLocationDaemon(interval);
		new Thread(daemon).start();
	}

	protected void stopBackend() {
		if (daemon == null)
			return;

		daemon.end();
		daemon = null;
	}
}
