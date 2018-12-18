package jsr135;

import javax.microedition.media.*;
import javax.microedition.media.control.*;
import javax.microedition.media.protocol.*;

class ToneControlImpl implements ToneControl {

    private byte[] bSequence = null;
    private TonePlayer tonePlayer = null;

    private int pos = 0;
    private boolean[] blk_defined = new boolean[128];

    public ToneControlImpl(TonePlayer player) {
        tonePlayer = player;
    }

    /** Validates single sequence_event;
      * If succeeded, after return 'pos' points to next byte after
      * validated event
      * @return null if success, error message otherwize
      */
    private String checkSequenceEvent( byte[] seq ) {

        byte evt = seq[ pos ];
        byte blk, dur, vol, rep;

        switch ( evt ) {
        case ToneControl.PLAY_BLOCK:
            blk = seq[ pos + 1 ];
            if ( blk < 0 ) return "invalid block number '" + blk + "'";
            if ( !blk_defined[ blk ] ) return "block #" + blk + " undefined";
            pos += 2;
            break;
        case ToneControl.SET_VOLUME:
            vol = seq[ pos + 1 ];
            if ( vol < 0 || vol > 100 ) return "invalid volume '" + vol + "'";
            pos += 2;
            break;
        case ToneControl.REPEAT:
            rep = seq[ pos + 1 ];
            evt = seq[ pos + 2 ];
            dur = seq[ pos + 3 ];
            if ( rep < 2 ) return "invalid repeat count '" + rep + "'";
            if ( evt == ToneControl.SILENCE || evt >= 0 ) {
                if ( dur < 1 ) return "invalid duration '" + dur + "'";
            } else {
                return "invalid repeated event '" + evt + "'";
            }
            pos += 4;
            break;
            /*
                    case DualToneControl.DUALTONE:
                        if( !dualTone ) return "dualtones not supported";
                        if( seq[ pos + 1 ] < 0 ) return "invalid dualtone 1st param '" + seq[ pos + 1 ] + "'";
                        if( seq[ pos + 2 ] < 0 ) return "invalid dualtone 2nd param '" + seq[ pos + 2 ] + "'";
                        if( seq[ pos + 3 ] < 0 ) return "invalid dualtone 3rd param '" + seq[ pos + 3 ] + "'";
                        pos += 4;
                        break;
            */
        default: // note or SILENCE
            if ( evt == ToneControl.SILENCE || evt >= 0 ) {
                dur = seq[ pos + 1 ];
                if ( dur < 1 ) return "invalid duration '" + dur + "'";
                pos += 2;
            } else {
                return "invalid sequence event '" + evt + "'";
            }
        }

        return null;
    }

    /** Validates tone sequence
      * @return null if success, error message otherwize
      */
    private String checkSequence( byte[] seq ) {

        for ( int i = 0; i < 128; i++ ) {
            blk_defined[ i ] = false;
        }

        // version
        if ( seq.length < 2 || ToneControl.VERSION != seq[ 0 ] ) {
            return "missing version information";
        }

        if ( 1 != seq[ 1 ] ) {
            return "incompatible version '" + seq[ 1 ] + "'";
        }

        pos = 2;

        // *1 tempo_definition
        if ( pos < seq.length && ToneControl.TEMPO == seq[ pos ] ) {
            if ( seq[ pos + 1 ] < 5 ) {
                return "invalid tempo value '" + seq[ pos + 1 ] + "'";
            }
            pos += 2;
        }

        // *1 resolution_definition
        if ( pos < seq.length && ToneControl.RESOLUTION == seq[ pos ] ) {
            if ( seq[ pos + 1 ] < 1 ) {
                return "invalid resolution value '" + seq[ pos + 1 ] + "'";
            }
            pos += 2;
        }

        // * block_definition
        byte    blk;
        int     blk_len;

        // BLOCK_START
        while ( pos < seq.length && ToneControl.BLOCK_START == seq[ pos ] ) {
            // block_number
            blk = seq[ pos + 1 ];
            if ( blk < 0 ) {
                return "invalid block number '" + blk + "'";
            }
            pos += 2;
            blk_len = 0;

            // 1*sequence_event BLOCK_END
            while ( ToneControl.BLOCK_END != seq[ pos ] ) {
                String estr = checkSequenceEvent( seq );
                if ( null != estr ) {
                    return estr;
                }
                blk_len++;
            }
            if ( 0 == blk_len ) {
                return "block #" + blk + " is empty.";
            }

            // block_number
            if ( blk != seq[ pos + 1 ] ) {
                return "block #" + blk +
                       ": mismatching closing block number '" + seq[ pos + 1 ] + "'";
            }
            blk_defined[ blk ] = true;
            pos += 2;
        }

        // 1* sequence_event
        int evt_count = 0;
        while ( pos < seq.length ) {
            String estr = checkSequenceEvent( seq );
            if ( null != estr ) {
                return estr;
            }
            evt_count++;
        }
        if ( 0 == evt_count ) {
            return "sequence contains no sequence events";
        }

        return null;
    }

    public void setSequence(byte[] sequence) {
        String estr = null;

        if (sequence == null)
            throw new IllegalArgumentException("null tone sequence");

        if (tonePlayer.getState() >= Player.PREFETCHED)
            throw new IllegalStateException("cannot set seq after prefetched");

        try {
            estr = checkSequence(sequence);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            estr = "unexpected end of sequence";
        }

        if (null != estr) {
            throw new IllegalArgumentException("Tone sequence check failed at offset " +
                                               pos + ": " + estr );
        }

        bSequence = new byte[sequence.length];
        for (int i=0; i<sequence.length; i++)
            bSequence[i] = sequence[i];
    }

    protected byte[] getSequence() {
        return bSequence;
    }

    protected boolean hasToneSequenceSet() {
        return (bSequence != null);
    }
}
