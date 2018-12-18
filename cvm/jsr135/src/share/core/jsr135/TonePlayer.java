package jsr135;

import java.io.*;
import java.util.*;

import javax.microedition.media.*;
import javax.microedition.media.control.*;
import javax.microedition.media.protocol.*;

public class TonePlayer implements Player, Runnable {
    private TimeBase timeBase = null;
    private ToneControlImpl toneControl = null;
    private Vector listeners = null;
    private String mimetype = null;

    private long mediaTime = Player.TIME_UNKNOWN;
    private int state = Player.CLOSED;
    private int loopCount = 0;

    public TonePlayer() {
        toneControl = new ToneControlImpl(this);
        state = Player.UNREALIZED;
    }

    public void debug(String s) {
        if (false) {
            System.out.println("TONE PLAYER: " + s);
        }
    }

    public void realize() throws MediaException {
        debug("Realize tone player");

        if ((state == Player.REALIZED) || (state == Player.PREFETCHED) || (state == Player.STARTED))
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot realize when closed");

        state = Player.REALIZED;
    }

    public void prefetch() throws MediaException {
        debug("Prefetch tone player");

        if (state == Player.STARTED)
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot prefetch when closed");

        if (state == Player.UNREALIZED)
            realize();

        state = Player.PREFETCHED;
    }

    public void start() throws MediaException {
        debug("Start tone player");

        if ((state == Player.UNREALIZED) || (state == Player.REALIZED))
            prefetch();

        if (state == Player.STARTED)
            return;

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot starter when closed");

        state = Player.STARTED;

        Thread t = new Thread(this);
        t.start();
    }

    public void stop() throws MediaException {
        debug("Stop tone player");

        if (state == Player.CLOSED)
            throw new IllegalStateException("cannot stop when closed");

        state = Player.PREFETCHED;
    }

    public void deallocate() {
        debug("Deallocate tone player");

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

    public void close() {
        debug("Close tone player");
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

        return "audio/x-tone-seq";
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
        if (controlType.equals("ToneControl"))
            return toneControl;

        return null;
    }

    public Control[] getControls() {
        return new Control[] { toneControl };
    }

    public boolean open(InputStream stream, String type) throws MediaException {
        mimetype = type;

        int chunksize = 128;
        byte[] tmpseqs = new byte[chunksize];
        byte[] seqs = null;
        ByteArrayOutputStream baos = new ByteArrayOutputStream(chunksize);

        try {
            int read;

            while ((read = stream.read(tmpseqs, 0, chunksize)) != -1) {
                baos.write(tmpseqs, 0, read);
            }

            seqs = baos.toByteArray();
            baos.close();
            tmpseqs = null;

            stream.close();

            try {
                toneControl.setSequence(seqs);
            }
            catch (Exception e) {
                throw new MediaException("unable to realize: " + e.getMessage());
            }
        }
        catch (IOException ex) {
            throw new MediaException("unable to realize: fail to read from source");
        }

        return true;
    }

    public void setTimeBase(TimeBase master) throws MediaException {
        timeBase = master;
    }

    public TimeBase getTimeBase() {
        return timeBase;
    }

    private byte[] flattenSequence(byte[] sequence) {
        boolean process = false;

        if (sequence == null)
            return null;

        // Inline play block events
        for (int pos=0; pos < sequence.length; pos++) {
            if (sequence[pos] == ToneControl.PLAY_BLOCK) {
                int block = sequence[pos+1];
                for (int start=0; start < sequence.length; start++) {
                    if ((sequence[start] == ToneControl.BLOCK_START) && (sequence[start+1] == block)) {
                        for (int end=start+2; end < sequence.length; end++) {
                            if ((sequence[end] == ToneControl.BLOCK_END) && (sequence[end+1] == block)) {
                                int count = end - start - 2;
                                byte[] newsequence = new byte[sequence.length + count - 2];
                                for (int i=0; i<pos; i++) {
                                    newsequence[i] = sequence[i];
                                }
                                for (int j=0; j<count; j++) {
                                    newsequence[pos+j] = sequence[start+2+j];
                                }
                                for (int k=pos+2; k<sequence.length; k++) {
                                    newsequence[count-2+k] = sequence[k];
                                }
                                sequence = newsequence;
                                break;
                            }
                        }
                        break;
                    }
                }
            } else if (sequence[pos] == ToneControl.REPEAT) {
                // Roll out repeat
                byte multiplier = sequence[pos+1];
                byte note = sequence[pos+2];
                byte duration = sequence[pos+3];

                byte[] newsequence = new byte[sequence.length + multiplier*2 - 2];
                for (int i=0; i<pos; i++) {
                    newsequence[i] = sequence[i];
                }
                for (int j=0; j<multiplier; j++) {
                    newsequence[pos+j*2+0] = note;
                    newsequence[pos+j*2+1] = duration;
                }
                for (int k=pos+4; k<sequence.length; k++) {
                    newsequence[multiplier*2-4+k] = sequence[k];
                }
                sequence = newsequence;
            }
        }

        // Strip block definitions
        byte[] newsequence = new byte[sequence.length];
        int idx=0;
        for (int pos=0; pos < sequence.length; pos++) {
            if (sequence[pos] == ToneControl.BLOCK_START) {
                while (sequence[pos] != ToneControl.BLOCK_END) pos++;
                pos++;
            } else {
                newsequence[idx] = sequence[pos];
                idx++;
            }
        }

        sequence = new byte[idx];
        for (int pos=0; pos < sequence.length; pos++) {
            sequence[pos] = newsequence[pos];
        }

        return sequence;
    }

    public void run() {
        byte[] sequence = toneControl.getSequence();
        if (sequence == null) {
            throw new IllegalStateException("tone sequence not set");
        }

        debug("  length: " + sequence.length);
        sequence = flattenSequence(sequence);

        if (sequence == null) {
            throw new IllegalStateException("tone sequence not flattened");
        }

        debug("  flattened length: " + sequence.length);

        // 5 <= tempo_modifier <= 127, 20bpm to 508bpm, default 120bpm
        // multiply by 4 to get the tempo (in bpm) used in the sequence
        int tempo_modifier = 30;

        // 1 <= resolution_unit <= 127, 1/1 note to 1/127 note, default 1/64 note
        int resolution_unit = 64;

        // 0 <= volume <= 100, 0% to 100% volume, default 100%
        int volume = 100;

        // 1 <= duration <= 127
        // Duration in msec: duration * 60 * 1000 * 4 / (resolution * tempo)
        int note = 0;
        int duration = 0;

        int pos=2;

        if (sequence[pos] == ToneControl.TEMPO) {
            tempo_modifier = sequence[pos+1];
            pos += 2;
        }

        if (sequence[pos] == ToneControl.RESOLUTION) {
            resolution_unit = sequence[pos+1];
            pos += 2;
        }

        tempo_modifier = 60;
        try {
            while ((pos < sequence.length) && (state == Player.STARTED)) {
                if (sequence[pos] == ToneControl.SET_VOLUME) {
                    volume = sequence[pos+1];
                } else if (sequence[pos] == ToneControl.SILENCE) {
                    duration = sequence[pos+1];

                    int delay = duration * 60 * 1000 * 4 / (resolution_unit * tempo_modifier);
                    Thread.sleep(delay);
                } else {
                    note = sequence[pos];
                    duration = sequence[pos+1];

                    int delay = duration * 60 * 1000 * 4 / (resolution_unit * tempo_modifier);
                    Manager.playTone(note, delay - 25, volume);
                    Thread.sleep(delay);
                }
                pos += 2;
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
