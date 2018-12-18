package jsr135;

import java.io.*;
import java.util.*;

import javax.microedition.media.*;
import javax.microedition.media.control.*;
import javax.microedition.media.protocol.*;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.ClassNotFoundException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class MaemoMediaPlayer implements Player {
    private TimeBase timeBase = Manager.getSystemTimeBase();
    private Vector listeners = null;
    private String mimetype = null;

    private long mediaTime = Player.TIME_UNKNOWN;
    private int state = Player.CLOSED;
    private int loopCount = 0;

    private String maemoHashCode = null;

    private static native String[] maemoMediaPlayer(String params[]);


    public static void init() {
    }

    public MaemoMediaPlayer(String uri, String type) {
        state = Player.UNREALIZED;
        mimetype = type;

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "create", uri });

        maemoHashCode = "" + (Math.abs(hashCode()) % 1000000);
        while (maemoHashCode.length() < 6)
            maemoHashCode = "0" + maemoHashCode;
    }

    public MaemoMediaPlayer(InputStream stream, String type) {
        state = Player.UNREALIZED;

        mimetype = type;

        String num = "" + (Math.abs(hashCode()) % 1000000);
        while (num.length() < 6)
            num = "0" + num;

        String uri = null;
        if (type.equals("audio/x-wav")) {
            uri = "/home/user/MyDocs/phoneme-cache/" + num + ".wav";
        }

        if (type.equals("audio/mpeg")) {
            uri = "/home/user/MyDocs/phoneme-cache/" + num + ".mp3";
        }

        if (type.equals("audio/midi")) {
            uri = "/home/user/MyDocs/phoneme-cache/" + num + ".midi";
        }

        if (uri == null)
            return;

        int chunksize = 16384;
        byte[] tmpaudio = new byte[chunksize];

        try {
            File tmp = new File("/home/user/MyDocs/phoneme-cache");
            tmp.mkdirs();

            FileOutputStream fos = new FileOutputStream(new File(uri));

            int read;

            while ((read = stream.read(tmpaudio, 0, chunksize)) != -1) {
                fos.write(tmpaudio, 0, read);
            }

            fos.close();
            tmpaudio = null;

            stream.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "create", uri });
        maemoHashCode = "0123456789";
    }

    public void debug(String s) {
        if (false) {
            System.out.println("MEDIA PLAYER: " + s);
        }
    }

    public void realize() throws MediaException {
        debug("Realize audio player");

        if ((state == Player.REALIZED) || (state == Player.PREFETCHED) || (state == Player.STARTED))
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot realize when closed");

        state = Player.REALIZED;
    }

    public synchronized void prefetch() throws MediaException {
        debug("Prefetch audio player");

        if (state == Player.STARTED)
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot prefetch when closed");

        if (state == Player.UNREALIZED)
            realize();

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "prepare", maemoHashCode });

        state = Player.PREFETCHED;
    }

    public synchronized void start() throws MediaException {
        debug("Start audio player");

        if ((state == Player.UNREALIZED) || (state == Player.REALIZED))
            prefetch();

        if (state == Player.STARTED)
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot starter when closed");

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "start", maemoHashCode });

        state = Player.STARTED;
    }

    public synchronized void stop() throws MediaException {
        debug("Stop audio player");

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot stop when closed");

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "stop", maemoHashCode });

        state = Player.PREFETCHED;
    }

    public void deallocate() {
        debug("Deallocate audio player");

        if ((state == Player.UNREALIZED) || (state == Player.REALIZED))
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot stop when closed");

        if (state == Player.STARTED) {
            try {
                stop();
            }
            catch (MediaException e) {}
        }

        state = Player.REALIZED;
    }

    public synchronized void close() {
        debug("Close audio player");

        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "release", maemoHashCode });

        state = Player.CLOSED;
    }

    public long setMediaTime(long now) throws MediaException {
        if ((state == Player.UNREALIZED) || (state == Player.CLOSED))
            throw new IllegalStateException("cannot set media time when unrealized or closed");

        mediaTime = now;
        return mediaTime;
    }

    public long getMediaTime() {
        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot get media time when closed");

        return mediaTime;
    }

    public int getState() {
        return state;
    }

    public long getDuration() {
        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot get duration when closed");

        return Player.TIME_UNKNOWN;
    }

    public String getContentType() {
        if ((state == Player.UNREALIZED) || (state == Player.CLOSED))
            throw new IllegalStateException("cannot get content type when unrealized or closed");

        return mimetype;
    }

    public void setLoopCount(int count) {
        if ((state == Player.STARTED) || (state == Player.CLOSED))
            throw new IllegalStateException("cannot set loop count when started or closed");

        loopCount = count;
    }

    public void addPlayerListener(PlayerListener playerListener) {
        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot add listener when closed");

        if (listeners == null)
            listeners = new Vector();
        listeners.addElement(playerListener);
    }

    public void removePlayerListener(PlayerListener playerListener) {
        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot remove listener when closed");

        if (listeners == null)
            return;

        listeners.removeElement(playerListener);
    }

    public Control getControl(String controlType) {
        return null;
    }

    public Control[] getControls() {
        return new Control[] { };
    }

    public void setTimeBase(TimeBase master) throws MediaException {
        timeBase = master;
    }

    public TimeBase getTimeBase() {
        return timeBase;
    }

    public static void playTone(int note, int duration, int volume) {
        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "playTone", ""+note, ""+duration, ""+volume });
    }

    public static void playAlert(int type) {
        maemoMediaPlayer(new String[] { "maemo.media.MediaPlayer", "playAlert", ""+type });
    }
}
