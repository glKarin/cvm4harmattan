/*
 * @(#)Protocol.java	1.13 06/10/10
 *
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
 */

/*
 * NOTE - This code is written a somewhat unusual, and not very object oriented, way.
 * The principal reason for this is that we intend to translate much of this
 * protocol into C and place it in the KVM kernel where is will be much smaller
 * and faster.
 */

package com.sun.cdc.io.j2me.file;

import com.sun.j2me.security.Token;

import com.sun.j2me.jsr75.*;
import java.io.*;
import java.util.*;
import javax.microedition.io.*;
import javax.microedition.io.file.*;

/**
 * This implements the default "file:" protocol J2SE
 * <p>
 * This class represents the internal functions that are written in C for KVM
 * in the file storagePrim.c
 *
 * @version 2.0 2/21/2000
 */
public class Protocol extends ProtocolNative implements FileConnection {

    /* File handle */
    private RandomAccessFile _raf_;

    /* The directory opened */
    private String _directory_;

    /* Currently selected file */
    private String _selection_;

    /* Current permission to read and/or write */
    private int _mode_;

    /* Current parameters for selected file */
    private String _parms_;

    /* Security token for using FileConnection API from PIM */
    private Token _classSecurityToken_;

    public static Vector listRoots() {
        // System.out.println("FC: listRoots()");

        Vector v = new Vector();
        v.addElement("/PIMdb/");
        v.addElement("/MyDocs/");
        v.addElement("/FileSystem/");
        return v;
    }

    public Connection openPrim(String name, int mode, boolean timeouts) throws IOException {
        if (name.startsWith("//localhost"))
            return super.openPrim("//" + name.substring(11), mode, timeouts);
        else
            return super.openPrim(name, mode, timeouts);
    }

    /**
     * Opens the file connection and receive security token.
     * @param token security token from PIM
     * @param name URL path fragment
     * @return an opened Connection
     * @throws IOException if some other kind of I/O error occurs.
     */
    public Connection openPrim(Token token, String name) throws IOException {
        return openPrim(token, name, Connector.READ_WRITE);
    }

    /**
     * Opens the file connection and receive security token.
     * @param token security token from PIM
     * @param name URL path fragment
     * @param mode access mode
     * @return an opened Connection
     *  @throws IOException if some other kind of I/O error occurs.
     */
    public Connection openPrim(Token token, String name, int mode) throws IOException {
        _classSecurityToken_ = token;
        return openPrim(name, mode, false);
    }

    /********************************************************************************/

    private boolean isOpen = false;

    private void debug(String msg) {
        // System.err.println(msg);
    }

    public boolean isOpen() {
        debug("FC: isOpen()");
        return isOpen;
    }

    public void close() throws IOException {
        debug("FC: close()");
        if (isOpen) {
            prim_closeProtocol();
            isOpen = false;
        }
    }

    public InputStream openInputStream() throws IOException {
        debug("FC: openInputStream()");
        InputStream is = super.openInputStream();
        isOpen = true;

        return is;
    }

    public DataInputStream openDataInputStream() throws IOException {
        debug("FC: openDataInputStream()");
        return new DataInputStream(openInputStream());
    }

    public OutputStream openOutputStream() throws IOException {
        debug("FC: openOutputStream()");
        OutputStream os = super.openOutputStream();
        isOpen = true;

        return os;
    }

    public DataOutputStream openDataOutputStream() throws IOException {
        debug("FC: openDataOutputStream()");
        return new DataOutputStream(openOutputStream());
    }

    public OutputStream openOutputStream(long byteOffset) throws IOException {
        debug("FC: openOutputStream(" + byteOffset + ")");
        OutputStream os = openOutputStream();
        if (byteOffset > 0) {
            try {
                seek(byteOffset);
            }
            catch (IOException e) {
                System.err.println("FC: Seeking to byte offset " + byteOffset + " failed!");
                throw e;
            }
        }
        return os;
    }

    public native long totalSize0();
    public native long availableSize0();

    public long totalSize() {
        debug("FC: totalSize(): " + -1);
        return totalSize0();
    }

    public long availableSize() {
        debug("FC: availableSize()");
        return availableSize0();
    }

    public long usedSize() {
        debug("FC: usedSize(): " + (totalSize() - availableSize()));
        return totalSize() - availableSize();
    }

    private long directorySize(String dir, boolean includeSubDirs) {
        long size = 0;

        if (dir == null)
            return 0;

        File file = new File(dir);
        if (!file.exists() || !file.isDirectory())
            return 0;

        String[] s = file.list();
        for (int i=0; i<s.length; i++) {
            file = new File(dir + "/" + s[i]);
            if (file.isDirectory()) {
                if (includeSubDirs)
                    size += directorySize(dir + "/" + s[i], includeSubDirs);
            } else {
                size += file.length();
            }
        }

        return size;
    }

    public long directorySize(boolean includeSubDirs) throws IOException {
        debug("FC: directorySize(" + includeSubDirs + ")");
        return directorySize(getDirectory(), includeSubDirs);
    }

    public long fileSize() throws IOException {
        debug("FC: fileSize(): " + prim_lengthOf());
        return prim_lengthOf();
    }

    public boolean canRead() {
        debug("FC: canRead()");
        return prim_canRead();
    }

    public boolean canWrite() {
        debug("FC: canWrite()");
        return prim_canWrite();
    }

    public boolean isHidden() {
        debug("FC: isHidden(): false");
        return false;
    }

    public void setReadable(boolean readable) throws IOException {
        debug("FC: setReadable(" + readable + ")");
        if(!prim_setReadable(readable)) {
            throw new SecurityException();
        }
    }

    public void setWritable(boolean writable) throws IOException {
        debug("FC: setWritable(" + writable + ")");
        if(!prim_setWritable(writable)) {
            throw new SecurityException();
        }
    }

    public void setHidden(boolean hidden) throws IOException {
        debug("FC: setHidden(" + hidden + ")");
    }

    public Enumeration list() throws IOException {
        debug("FC: list() [" + getDirectory() + "]");
        Vector v = new Vector();

        File file = new File(getDirectory());
        if(!file.exists()) {
            debug("FC: File " + file + " does not exist!");
            return v.elements();
        }
        String[] s = file.list();
        for (int i=0; i<s.length; i++) {
            if (prim_isDirectory(s[i]))
                v.addElement(s[i] + "/");
            else
                v.addElement(s[i]);
        }
        Collections.sort(v);
        return v.elements();
    }

    private boolean filterAccept(String filter, String str) {
        if (filter == null) {
            return true;
        }

        if (filter.length() == 0) {
            return false;
        }

        int currPos = 0;
        int currComp = 0, firstSigComp = 0;
        int idx;

        // Splitted string does not contain separators themselves
        String components[] = StringUtil.split(filter, '*', 0);

        // if filter does not begin with '*' check that string begins with
        // filter's first component
        if (filter.charAt(0) != '*') {
            if (!str.startsWith(components[0])) {
                return false;
            } else {
                currPos += components[0].length();
                currComp++;
                firstSigComp = currComp;
            }
        }

        // Run on the string and check that it contains all filter
        // components sequentially
        int strLen = str.length();
        for (; currComp < components.length; currComp++) {
            int compLen = components[currComp].length();
            // Looking for empty component at str.length() is a special case
            if (currPos != strLen || compLen != 0) {
                idx = str.indexOf(components[currComp], currPos);
                if (idx != -1) {
                    currPos = idx + compLen;
                } else {
                    // run out of the string while filter components remain
                    return false;
                }
            }
        }

        // At this point we run out of filter. First option is that
        // filter ends with '*', or string is finished,
        // we are fine then, and accept the string.
        //
        // In the other case we check that string ends with the last component
        // of the filter (given that there was an asterisk before the last
        // component
        if (!(filter.charAt(filter.length() - 1) == '*'
                || currPos == strLen)) {
            if (components.length > firstSigComp) {
                // does string end with the last filter component?
                if (!str.endsWith(components[components.length - 1])) {
                    return false;
                }
            } else {
                // there was no asteric before last filter component
                return false;
            }
        }

        // If we got here string is accepted
        return true;
    }

    public Enumeration list(String filter, boolean includeHidden) throws IOException {
        debug("FC: list(" + filter + "," + includeHidden + ") [" + getDirectory() + "]");
        Vector v = new Vector();

        File file = new File(getDirectory());
        if(!file.exists()) {
            return v.elements();
        }
        String[] s = file.list();
        if (filter.indexOf('*') >= 0) {
            for (int i=0; i<s.length; i++) {
                if (filterAccept(filter, s[i])) {
                    if (prim_isDirectory(s[i]))
                        v.addElement(s[i] + "/");
                    else
                        v.addElement(s[i]);
                }
            }
        } else {
            for (int i=0; i<s.length; i++) {
                if (s[i].equalsIgnoreCase(filter)) {
                    if (prim_isDirectory(s[i]))
                        v.addElement(s[i] + "/");
                    else
                        v.addElement(s[i]);
                }
            }
        }
        Collections.sort(v);
        return v.elements();
    }

    public void mkdir() throws IOException {
        debug("FC: mkdir()");
        prim_createDirectoryAndSelect(prim_getSelectionName());
    }

    public void create() throws IOException {
        debug("FC: create()");
        prim_createFileAndSelect(prim_getSelectionName());
    }

    public boolean exists() {
        debug("FC: exists(): " + prim_exists());
        return prim_exists();
    }

    public boolean isDirectory() {
        debug("FC: isDirectory(): " + prim_isDirectory());
        return prim_isDirectory();
    }

    public void delete() throws IOException {
        debug("FC: delete() [" + formName(prim_getSelectionName()) + "]");
        prim_deleteItem();
    }

    public void rename(String newName) throws IOException {
        debug("FC: rename(" + newName + ")");
        if (prim_isDirectory())
            prim_renameDirectory(newName);
        else
            prim_renameFile(newName);
    }

    public void truncate(long byteOffset) throws IOException {
        debug("FC: truncate(" + byteOffset + ")");
        prim_setLength(byteOffset);
    }

    public void setFileConnection(String fileName) throws IOException {
        debug("FC: setFileConnection(" + fileName + ")");

        if ((fileName == null) || (fileName.equals(".."))) {
            throw new IOException("Cannot set FileConnection to '" + fileName + "'");
        }

        int dirindex = fileName.indexOf('/');
        if (dirindex != -1 && dirindex != (fileName.length() - 1)) {
            throw new IllegalArgumentException("Contains any path specification");
        }

        if (!prim_isDirectory()) {
            throw new IOException("Current FileConnection is not a directory");
        }

        if (!prim_exists(fileName)) {
            throw new IllegalArgumentException("New target does not exists");
        }

        prim_openProtocol(fileName, _parms_, _mode_);
    }

    public String getName() {
        debug("FC: getName(): " + prim_getSelectionName());
        return prim_getSelectionName();
    }

    public String getPath() {
        debug("FC: getPath(): " + getDirectory());
        return getDirectory();
    }

    public String getURL() {
        debug("FC: getURL(): " + "file://" + formName(prim_getSelectionName()));
        return "file://" + formName(prim_getSelectionName());
    }

    public long lastModified() {
        debug("FC: lastModified()");

        long modified = -1;
        try {
            modified = prim_timeOf();
        }
        catch (Exception e) {}

        return modified;
    }

    /********************************************************************************/

    /*
     * setDirectory
     */
    private void setDirectory(String name) {
        if(name.length() == 0) {
            _directory_ = "";
        } else if(!name.endsWith("/")) {
            _directory_ = name + "/";
        } else {
            _directory_ = name;
        }
        setProtocolBaseDirectory(_directory_);
    }

    /*
     * getDirectory
     */
    protected String getDirectory() {
        return _directory_;
    }

    /*
     * formName
     */
    public String formName(String name) {
        if (name == null)
            return getDirectory();
        else
            return getDirectory()+name;
    }

    /*
     * prim_initialise
     */
    public Connection prim_openProtocol(String openName, String parms, int mode) throws IOException {
        String homePath = System.getProperty("sun.midp.home.path", "midp/midp_linux_fb_gcc").replace('\\', '/');

        debug("FC: openName: " + openName);

        String pimdb = homePath + "/appdb/pimdb";
        if (!(new File(pimdb).exists())) {
            new File(pimdb).mkdir();

            String pim = pimdb + "/pim";
            new File(pim).mkdir();
            new File(pim + "/contacts").mkdir();
            new File(pim + "/events").mkdir();
            new File(pim + "/todo").mkdir();

            new File(pim + "/contacts/" + System.getProperty("DefaultContactList", "Default_contact")).mkdir();
            new File(pim + "/events/" + System.getProperty("DefaultEventList", "Default_event")).mkdir();
            new File(pim + "/todo/" + System.getProperty("DefaultTodoList", "Default_todo")).mkdir();
        }

        openName.replace('\\', '/');
        while (openName.length() >= 2 && openName.charAt(0) == '/' && openName.charAt(1) == '/') {
            openName = openName.substring(1);
        }

        if (openName.startsWith("/PIMdb")) {
            openName = homePath + "/appdb/pimdb" + openName.substring(6);
        } else
        if (openName.startsWith("/MyDocs")) {
            if (!(new File("/home/user/MyDocs").exists()))
                new File("/home/user/MyDocs").mkdir();

            openName = "/home/user/MyDocs" + openName.substring(7);
        } else
        if (openName.startsWith("/FileSystem")) {
            openName = "" + openName.substring(11);
        }

        debug("FC: openName -> " + openName);

        setDirectory(""); /* Just so prim_exists() will work */

        if(prim_exists(openName) && prim_isDirectory(openName)) {
            setDirectory(openName);
            setSelection(null);
        } else {
            if(!prim_exists(openName) && !writing) {
                throw new ConnectionNotFoundException("No such file "+openName);
            }
            int slash = openName.lastIndexOf('/');
            if(slash == -1) {
                setDirectory("");
                setSelection(openName);
            } else {
                setDirectory(openName.substring(0, slash+1));
                String n = openName.substring(slash+1);
                if(n.length() > 0) {
                    setSelection(n);
                }
            }
            // Check for SecurityManager.checkWrite(filename) permission
            // only for WRITE and READ_WRITE mode.
            // NOTE: this will cause a java.lang.SecurityException if
            //       no permission for writing.
            if (mode != Connector.READ) {
                prim_canWrite();
                
                // Check for SecurityManager.checkRead(filename) permission
                // only for READ or READ_WRITE mode.
                // NOTE: this will cause a java.lang.SecurityException if
                //       no permission for reading.
            } else if ((mode == Connector.READ) || 
                       (mode == Connector.READ_WRITE)) {
                java.lang.SecurityManager sm = System.getSecurityManager();
                if ((sm != null) && (openName != null)) {
                      sm.checkRead(openName);
                }
            }
        }

        _mode_ = mode;
        _parms_ = parms;

        return this;
    }


    /*
     * prim_closeProtocol
     */
    public void prim_closeProtocol() throws IOException {
        debug("FC: prim_closeProtocol()");

        prim_close();
        _directory_ = null;
        _selection_ = null;
    }

    /*
     * prim_realOpen
     */
    public void prim_realOpen() throws IOException {
        debug("FC: prim_realOpen()");
        String name = formName(prim_getSelectionName());
        if (_mode_ == Connector.READ) {
            _raf_ = new RandomAccessFile(name, "r");
        } else
        if (_mode_ == Connector.WRITE) {
            _raf_ = new RandomAccessFile(name, "rw");
        } else
        if (_mode_ == Connector.READ_WRITE) {
            _raf_ = new RandomAccessFile(name, "rw");
        }
    }

    /*
     * prim_close
     */
    void prim_close() throws IOException {
        debug("FC: prim_close()");
        if (_raf_ != null) {
            RandomAccessFile f = _raf_;
            _raf_ = null;
            f.close();
        }
    }

    /*
     * setSelection
     */
    private void setSelection(String thing) throws IOException {
        debug("FC: setSelection(" + thing + ")");
        _selection_ = thing;
        if(thing == null) {
            prim_close();
        }
    }

    /*
     * prim_clearSelection
     */
    public void prim_clearSelection() throws IOException {
        debug("FC: prim_clearSelection()");
        setSelection(null);
    }

    /*
     * prim_isSelected
     */
    public boolean prim_isSelected() {
        debug("FC: prim_isSelected()");
        return _selection_ != null;
    }

    /*
     * getSelectionName
     */
    public String prim_getSelectionName() {
        debug("FC: prim_getSelectionName()");
        return (String)_selection_;
    }

    /*
     * getSelectionNumber
     */
    public int prim_getSelectionNumber() throws IOException {
        debug("FC: prim_getSelectionNumber()");
        try {
            return Integer.parseInt(prim_getSelectionName());
        } catch(NumberFormatException x) {
            throw new IOException("NumberFormatException");
        }
    }

    public void prim_findFirstItemAndSelect() throws IOException {
        debug("FC: prim_findFirstItemAndSelect()");
        setSelection(prim_findFirstItem());
    }

    public void prim_findItemAndSelect(String name) throws IOException {
        debug("FC: prim_findItemAndSelect(" + name + ")");
        setSelection(prim_findItem(name));
    }

    public void prim_findItemAndSelectByInt(int i) throws IOException {
        debug("FC: prim_findItemAndSelectByInt(" + i + ")");
        setSelection(prim_findItem(String.valueOf(i)));
    }

    public void prim_findItemAfterSelectionAndSelect() throws IOException {
        debug("FC: prim_findItemAfterSelectionAndSelect()");
        setSelection(prim_findItemAfter(prim_getSelectionName()));
    }

    public void prim_createAndSelect() throws IOException {
        debug("FC: prim_createAndSelect()");
        setSelection(prim_create());
    }

    public void prim_createFileAndSelect(String name) throws IOException {
        debug("FC: prim_createFileAndSelect(" + name + ")");
        setSelection(prim_createFile(name));
    }

    public void prim_createFileAndSelectByInt(int i) throws IOException {
        debug("FC: prim_createFileAndSelectByInt(" + i + ")");
        setSelection(prim_createFile(String.valueOf(i)));
    }

    public void prim_createDirectoryAndSelect(String name) throws IOException {
        debug("FC: prim_createDirectoryAndSelect(" + name + ")");
        setSelection(prim_createDirectory(name));
    }

    public boolean prim_deleteItem() {
        debug("FC: prim_deleteItem()");
        return prim_deleteItem(prim_getSelectionName());
    }

    public boolean prim_renameFile(String name2) {
        debug("FC: prim_renameFile(" + name2 + ")");
        return prim_renameItem(prim_getSelectionName(), name2);
    }

    public boolean prim_renameFileByInt(int i) {
        debug("FC: prim_renameFileByInt(" + i + ")");
        return prim_renameItem(prim_getSelectionName(), String.valueOf(i));
    }

    public boolean prim_renameDirectory(String name2) {
        debug("FC: prim_renameDirectory(" + name2 + ")");
        return prim_renameItem(prim_getSelectionName(), name2);
    }

    public long prim_lengthOf() throws IOException {
        debug("FC: prim_lengthOf()");
        return prim_lengthOf(prim_getSelectionName());
    }

    public void prim_setLength(long len) throws IOException {
        debug("FC: prim_setLength(" + len + ")");
        throw new RuntimeException("prim_setLength not implemented");
    }

    public long prim_timeOf() throws IOException {
        debug("FC: prim_timeOf()");
        return prim_timeOf(prim_getSelectionName());
    }

    public boolean prim_exists() {
        debug("FC: prim_exists()");
        return prim_exists(prim_getSelectionName());
    }

    public boolean prim_isDirectory() {
        debug("FC: prim_isDirectory()");
        return prim_isDirectory(prim_getSelectionName());
    }

    public boolean prim_canRead() {
        debug("FC: prim_canRead()");
        return prim_canRead(prim_getSelectionName());
    }

    public boolean prim_canWrite() {
        debug("FC: prim_canWrite()");
        return prim_canWrite(prim_getSelectionName());
    }

    public boolean prim_setReadable(boolean tf) {
        debug("FC: prim_setReadable(" + tf + ")");
        return prim_setReadable(prim_getSelectionName(), tf);
    }

    public boolean prim_setWritable(boolean tf) {
        debug("FC: prim_setWritable(" + tf + ")");
        return prim_setWritable(prim_getSelectionName(), tf);
    }


    /*
     * Real primitive methods
     */

   /*
     * prim_findFirstItem
     */
    String prim_findFirstItem() {
        File file = new File(getDirectory());
        if(!file.exists()) {
            return null;
        }
        String[] s = file.list();
        if(s.length == 0) {
            return null;
        }
        return s[0];
    }

    /*
     * prim_findItem
     */
    String prim_findItem(String name) {
        File file = new File(formName(name));
        if(!file.exists()) {
            return null;
        }
        return name;
    }

    /*
     * prim_findItemAfter
     */
    String prim_findItemAfter(String name) {
        File file = new File(getDirectory());
        if(!file.exists()) {
            return null;
        }
        String[] s = file.list();
        for(int i = 0 ; i < s.length-2 ; i++) {
            if(s[i].equals(name)) {
                return s[1+1];
            }
        }
        return null;
    }

    /*
     * prim_availableSpace
     */
    public long prim_availableSpace() {
        return Long.MAX_VALUE; //TEMP
    }

    /*
     * prim_countItems
     */
    public int prim_countItems() {
        File file = new File(getDirectory());
        if(!file.exists()) {
            return 0;
        }
        String[] s = file.list();
        return s.length;
    }

    /*
     * prim_create
     */
    String prim_create() throws IOException {
        File d = new File(getDirectory());
        File f = File.createTempFile("tmp", null, d);
        return f.getName();
    }

    /*
     * prim_createFile
     */
    String prim_createFile(String name)  throws IOException {
        FileOutputStream fos;
        if(prim_exists(name)) {
            throw new IOException("prim_createFile - file exists "+name);
        }
        fos = new FileOutputStream(formName(name));
        fos.close();
        return name;
    }

    /*
     * prim_createDirectory
     */
    String prim_createDirectory(String name)  throws IOException {
        if(new File(formName(name)).mkdir()) {
            return name;
        }
        throw new IOException("Could not prim_createDirectory()");
    }

    /*
     * prim_deleteItem
     */
    boolean prim_deleteItem(String name) {
        boolean res = new File(formName(name)).delete();

        if(res && prim_exists(name)) {
            throw new RuntimeException("Internal error - prim_deleteItem did not delete");
        }

        return res;
    }

    /*
     * prim_renameItem
     */
    boolean prim_renameItem(String name, String name2) {
        File to = new File(name2);
        return new File(formName(name)).renameTo(to);
    }

    /*
     * prim_lengthOf
     */
    long prim_lengthOf(String name) throws IOException {
        return new File(formName(name)).length();
    }

    /*
     * prim_timeOf
     */
    long prim_timeOf(String name) {
        return new File(formName(name)).lastModified();
    }

    /*
     * prim_exists
     */
    boolean prim_exists(String name) {
        return new File(formName(name)).exists();
    }

    /*
     * prim_isDirectory
     */
    boolean prim_isDirectory(String name) {
        debug("FC: prim_isDirectory(" + name + ") [" + new File(formName(name)) + "]: " + new File(formName(name)).isDirectory());
        return new File(formName(name)).isDirectory();
    }

    /*
     * prim_canRead
     */
    boolean prim_canRead(String name) {
        return new File(formName(name)).canRead();
    }

    /*
     * prim_canWrite
     */
    boolean prim_canWrite(String name) {
        return new File(formName(name)).canWrite();
    }

    /*
     * prim_setReadable
     */
    boolean prim_setReadable(String name, boolean tf) {
        return false;
    }

    /*
     * prim_setWritable
     */
    boolean prim_setWritable(String name, boolean tf) {
        return false;
    }

    /*
     * seek0
     */
    public void prim_seek(long pos) throws IOException {
        _raf_.seek(pos);
    }

    /*
     * getPosition0
     */
    public long prim_getPosition() throws IOException {
        return _raf_.getFilePointer();
    }

    /*
     * prim_read
     */
    public int prim_read() throws IOException {
        return _raf_.read();
    }

    /*
     * prim_readBytes
     */
    public int prim_readBytes(byte b[], int off, int len) throws IOException {
        return _raf_.read(b, off, len);
    }

    /*
     * prim_writeBytes
     */
    public void prim_write(int b) throws IOException {
        _raf_.write(b);
    }

    /*
     * prim_write
     */
    public void prim_writeBytes(byte b[], int off, int len) throws IOException {
        _raf_.write(b, off, len);
    }

/*
    public  native long    prim_availableSpace();
    public  native int     prim_countItems();
    private native String  prim_create() throws IOException;
    private native String  prim_createFile(String name) throws IOException;
    private native String  prim_createDirectory(String name) throws IOException;
    private native boolean prim_deleteItem(String name);
    private native boolean prim_renameItem(String name, String name2);
    private native long    prim_lengthOf(String name) throws IOException;
    private native long    prim_timeOf(String name);
    private native boolean prim_exists(String name);
    private native boolean prim_isDirectory(String name);
    private native boolean prim_canRead(String name);
    private native boolean prim_canWrite(String name);
    private native boolean prim_setReadable(String name, boolean tf);
    private native boolean prim_setWritable(String name, boolean tf);
    public  native void    prim_seek(long pos) throws IOException;
    public  native long    prim_getPosition() throws IOException;
    public  native int     prim_read() throws IOException;
    public  native int     prim_readBytes(byte b[], int off, int len) throws IOException;
    public  native void    prim_write(int b) throws IOException;
    public  native void    prim_writeBytes(byte b[], int off, int len) throws IOException;
*/
}
