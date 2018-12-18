
/**
 * Copyright  1990-2008 Sun Microsystems, Inc. All Rights Reserved.
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
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 *
 * These are constant defines both in native and Java layers.
 * NOTE: DO NOT EDIT. THIS FILE IS GENERATED. If you want to
 * edit it, you need to modify the corresponding XML files.
 *
 * Patent pending.
 */
package com.sun.midp.chameleon.keyboards;

import com.sun.midp.lcdui.Key;
import com.sun.midp.lcdui.VirtualKeyboard;
import java.util.Hashtable;
    
public class Keyboards {
    static Hashtable keyboards;

    private static void createKeyboardMap() {

        keyboards = new Hashtable();
    
            keyboards.put(VirtualKeyboard.LOWER_ALPHABETIC_KEYBOARD, new Key[][] {
            
                    {
                    
                        new Key('q',10, 20, Key.GENERAL_KEY )
                     , 
                        new Key('w',54, 20, Key.GENERAL_KEY )
                     , 
                        new Key('e',98, 20, Key.GENERAL_KEY )
                     , 
                        new Key('r',142, 20, Key.GENERAL_KEY )
                     , 
                        new Key('t',186, 20, Key.GENERAL_KEY )
                     , 
                        new Key('y',230, 20, Key.GENERAL_KEY )
                     , 
                        new Key('u',274, 20, Key.GENERAL_KEY )
                     , 
                        new Key('i',318, 20, Key.GENERAL_KEY )
                     , 
                        new Key('o',362, 20, Key.GENERAL_KEY )
                     , 
                        new Key('p',406, 20, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key('a',30, 80, Key.GENERAL_KEY )
                     , 
                        new Key('s',74, 80, Key.GENERAL_KEY )
                     , 
                        new Key('d',118, 80, Key.GENERAL_KEY )
                     , 
                        new Key('f',162, 80, Key.GENERAL_KEY )
                     , 
                        new Key('g',206, 80, Key.GENERAL_KEY )
                     , 
                        new Key('h',250, 80, Key.GENERAL_KEY )
                     , 
                        new Key('j',294, 80, Key.GENERAL_KEY )
                     , 
                        new Key('k',338, 80, Key.GENERAL_KEY )
                     , 
                        new Key('l',382, 80, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',10, 140, Key.CAPS_KEY )
                     , 
                        new Key('z',74, 140, Key.GENERAL_KEY )
                     , 
                        new Key('x',118, 140, Key.GENERAL_KEY )
                     , 
                        new Key('c',162, 140, Key.GENERAL_KEY )
                     , 
                        new Key('v',206, 140, Key.GENERAL_KEY )
                     , 
                        new Key('b',250, 140, Key.GENERAL_KEY )
                     , 
                        new Key('n',294, 140, Key.GENERAL_KEY )
                     , 
                        new Key('m',338, 140, Key.GENERAL_KEY )
                     , 
                        new Key(' ',406, 140, Key.BACKSPACE_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',142, 200, Key.NUMERIC_MODE_KEY )
                     , 
                        new Key(' ',190, 200, Key.GENERAL_KEY )
                     , 
                        new Key(' ',286, 200, Key.SYMBOL_MODE_KEY )
                     , 
                        new Key(' ',378, 200, Key.ENTER_KEY )
                     }
                
            }
            );
    
            keyboards.put(VirtualKeyboard.UPPER_ALPHABETIC_KEYBOARD, new Key[][] {
            
                    {
                    
                        new Key('Q',10, 20, Key.GENERAL_KEY )
                     , 
                        new Key('W',54, 20, Key.GENERAL_KEY )
                     , 
                        new Key('E',98, 20, Key.GENERAL_KEY )
                     , 
                        new Key('R',142, 20, Key.GENERAL_KEY )
                     , 
                        new Key('T',186, 20, Key.GENERAL_KEY )
                     , 
                        new Key('Y',230, 20, Key.GENERAL_KEY )
                     , 
                        new Key('U',274, 20, Key.GENERAL_KEY )
                     , 
                        new Key('I',318, 20, Key.GENERAL_KEY )
                     , 
                        new Key('O',362, 20, Key.GENERAL_KEY )
                     , 
                        new Key('P',406, 20, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key('A',30, 80, Key.GENERAL_KEY )
                     , 
                        new Key('S',74, 80, Key.GENERAL_KEY )
                     , 
                        new Key('D',118, 80, Key.GENERAL_KEY )
                     , 
                        new Key('F',162, 80, Key.GENERAL_KEY )
                     , 
                        new Key('G',206, 80, Key.GENERAL_KEY )
                     , 
                        new Key('H',250, 80, Key.GENERAL_KEY )
                     , 
                        new Key('J',294, 80, Key.GENERAL_KEY )
                     , 
                        new Key('K',338, 80, Key.GENERAL_KEY )
                     , 
                        new Key('L',382, 80, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',10, 140, Key.CAPS_KEY )
                     , 
                        new Key('Z',74, 140, Key.GENERAL_KEY )
                     , 
                        new Key('X',118, 140, Key.GENERAL_KEY )
                     , 
                        new Key('C',162, 140, Key.GENERAL_KEY )
                     , 
                        new Key('V',206, 140, Key.GENERAL_KEY )
                     , 
                        new Key('B',250, 140, Key.GENERAL_KEY )
                     , 
                        new Key('N',294, 140, Key.GENERAL_KEY )
                     , 
                        new Key('M',338, 140, Key.GENERAL_KEY )
                     , 
                        new Key(' ',406, 140, Key.BACKSPACE_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',142, 200, Key.NUMERIC_MODE_KEY )
                     , 
                        new Key(' ',190, 200, Key.GENERAL_KEY )
                     , 
                        new Key(' ',286, 200, Key.SYMBOL_MODE_KEY )
                     , 
                        new Key(' ',378, 200, Key.ENTER_KEY )
                     }
                
            }
            );
    
            keyboards.put(VirtualKeyboard.NUMERIC_KEYBOARD, new Key[][] {
            
                    {
                    
                        new Key('1',10, 20, Key.GENERAL_KEY )
                     , 
                        new Key('2',54, 20, Key.GENERAL_KEY )
                     , 
                        new Key('3',98, 20, Key.GENERAL_KEY )
                     , 
                        new Key('4',142, 20, Key.GENERAL_KEY )
                     , 
                        new Key('5',186, 20, Key.GENERAL_KEY )
                     , 
                        new Key('6',230, 20, Key.GENERAL_KEY )
                     , 
                        new Key('7',274, 20, Key.GENERAL_KEY )
                     , 
                        new Key('8',318, 20, Key.GENERAL_KEY )
                     , 
                        new Key('9',362, 20, Key.GENERAL_KEY )
                     , 
                        new Key('0',406, 20, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key('+',10, 80, Key.GENERAL_KEY )
                     , 
                        new Key('-',54, 80, Key.GENERAL_KEY )
                     , 
                        new Key('*',98, 80, Key.GENERAL_KEY )
                     , 
                        new Key('/',142, 80, Key.GENERAL_KEY )
                     , 
                        new Key('=',186, 80, Key.GENERAL_KEY )
                     , 
                        new Key('.',230, 80, Key.GENERAL_KEY )
                     , 
                        new Key(',',274, 80, Key.GENERAL_KEY )
                     , 
                        new Key(';',318, 80, Key.GENERAL_KEY )
                     , 
                        new Key('\u005C\u005c',362, 80, Key.GENERAL_KEY )
                     , 
                        new Key('\u0022',406, 80, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',10, 140, Key.CAPS_KEY )
                     , 
                        new Key('~',74, 140, Key.GENERAL_KEY )
                     , 
                        new Key('[',118, 140, Key.GENERAL_KEY )
                     , 
                        new Key(']',162, 140, Key.GENERAL_KEY )
                     , 
                        new Key('|',206, 140, Key.GENERAL_KEY )
                     , 
                        new Key('_',250, 140, Key.GENERAL_KEY )
                     , 
                        new Key('(',294, 140, Key.GENERAL_KEY )
                     , 
                        new Key(')',338, 140, Key.GENERAL_KEY )
                     , 
                        new Key(' ',406, 140, Key.BACKSPACE_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',142, 200, Key.ALPHA_MODE_KEY )
                     , 
                        new Key(' ',190, 200, Key.GENERAL_KEY )
                     , 
                        new Key(' ',286, 200, Key.SYMBOL_MODE_KEY )
                     , 
                        new Key(' ',378, 200, Key.ENTER_KEY )
                     }
                
            }
            );
    
            keyboards.put(VirtualKeyboard.SYBOLIC_KEYBOARD, new Key[][] {
            
                    {
                    
                        new Key('!',10, 20, Key.GENERAL_KEY )
                     , 
                        new Key('@',54, 20, Key.GENERAL_KEY )
                     , 
                        new Key('#',98, 20, Key.GENERAL_KEY )
                     , 
                        new Key('$',142, 20, Key.GENERAL_KEY )
                     , 
                        new Key('%',186, 20, Key.GENERAL_KEY )
                     , 
                        new Key('^',230, 20, Key.GENERAL_KEY )
                     , 
                        new Key('\u0026',274, 20, Key.GENERAL_KEY )
                     , 
                        new Key('*',318, 20, Key.GENERAL_KEY )
                     , 
                        new Key('(',362, 20, Key.GENERAL_KEY )
                     , 
                        new Key(')',406, 20, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key('+',10, 80, Key.GENERAL_KEY )
                     , 
                        new Key('-',54, 80, Key.GENERAL_KEY )
                     , 
                        new Key('*',98, 80, Key.GENERAL_KEY )
                     , 
                        new Key('/',142, 80, Key.GENERAL_KEY )
                     , 
                        new Key('=',186, 80, Key.GENERAL_KEY )
                     , 
                        new Key('.',230, 80, Key.GENERAL_KEY )
                     , 
                        new Key(',',274, 80, Key.GENERAL_KEY )
                     , 
                        new Key(';',318, 80, Key.GENERAL_KEY )
                     , 
                        new Key('\u005c\u005c',362, 80, Key.GENERAL_KEY )
                     , 
                        new Key('\u00a3',406, 80, Key.GENERAL_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',10, 140, Key.CAPS_KEY )
                     , 
                        new Key('~',74, 140, Key.GENERAL_KEY )
                     , 
                        new Key('_',118, 140, Key.GENERAL_KEY )
                     , 
                        new Key(':',162, 140, Key.GENERAL_KEY )
                     , 
                        new Key(' ',206, 140, Key.GENERAL_KEY )
                     , 
                        new Key('>',250, 140, Key.GENERAL_KEY )
                     , 
                        new Key('{',294, 140, Key.GENERAL_KEY )
                     , 
                        new Key('}',338, 140, Key.GENERAL_KEY )
                     , 
                        new Key(' ',406, 140, Key.BACKSPACE_KEY )
                     }
                 , 
                    {
                    
                        new Key(' ',142, 200, Key.ALPHA_MODE_KEY )
                     , 
                        new Key(' ',190, 200, Key.GENERAL_KEY )
                     , 
                        new Key(' ',286, 200, Key.SYMBOL_MODE_KEY )
                     , 
                        new Key(' ',378, 200, Key.ENTER_KEY )
                     }
                
            }
            );
    
            keyboards.put(VirtualKeyboard.GAME_KEYBOARD, new Key[][] {
            
                    {
                    
                        new Key(' ',80, 100, Key.LEFT_ARROW_KEY )
                     , 
                        new Key(' ',280, 100, Key.RIGHT_ARROW_KEY )
                     , 
                        new Key(' ',180, 20, Key.UP_ARROW_KEY )
                     , 
                        new Key(' ',180, 160, Key.DOWN_ARROW_KEY )
                     }
                
            }
            );
    
    }

    public static Hashtable getKeyboards() {
        createKeyboardMap();
        return keyboards;
    }
}
