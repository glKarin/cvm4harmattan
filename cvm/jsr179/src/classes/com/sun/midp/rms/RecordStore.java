package com.sun.midp.rms;

public abstract class RecordStore {

	public static final int AUTHMODE_PRIVATE = 0;
	public static final int AUTHMODE_ANY = 1;

	protected RecordStore() {
	}

	public abstract int addRecord(byte[] data, int offset, int count) throws RecordStoreNotOpenException, RecordStoreException, RecordStoreFullException;
	public abstract void addRecordListener(RecordListener listener);
	public abstract void closeRecordStore() throws RecordStoreNotOpenException, RecordStoreException;
	public abstract void deleteRecord(int recordId) throws RecordStoreNotOpenException, InvalidRecordIDException, RecordStoreException;
	public abstract long getLastModified() throws RecordStoreNotOpenException;
	public abstract String getName() throws RecordStoreNotOpenException;
	public abstract int getNextRecordID() throws RecordStoreNotOpenException, RecordStoreException;
	public abstract int getNumRecords() throws RecordStoreNotOpenException;
	public abstract byte[] getRecord(int recordId) throws RecordStoreNotOpenException, InvalidRecordIDException, RecordStoreException;
	public abstract int getRecord(int recordId, byte[] buffer, int offset) throws RecordStoreNotOpenException, InvalidRecordIDException, RecordStoreException, ArrayIndexOutOfBoundsException;
	public abstract int getRecordSize(int recordId) throws RecordStoreNotOpenException, InvalidRecordIDException, RecordStoreException;
	public abstract int getSize() throws RecordStoreNotOpenException;
	public abstract int getSizeAvailable() throws RecordStoreNotOpenException;
	public abstract int getVersion() throws RecordStoreNotOpenException;
	public abstract void removeRecordListener(RecordListener listener);
	public abstract void setRecord(int recordId, byte[] newData, int offset, int count) throws RecordStoreNotOpenException, InvalidRecordIDException, RecordStoreException, RecordStoreFullException;
	public abstract void setMode(int authmode, boolean writable) throws RecordStoreException;

	public static void deleteRecordStore(String recordStoreName) throws RecordStoreException, RecordStoreNotFoundException {
		throw new RecordStoreException("Record store not supported");
	}

	public RecordEnumeration enumerateRecords(RecordFilter filter, RecordComparator comparator, boolean keepUpdated) throws RecordStoreNotOpenException {
		throw new RecordStoreNotOpenException("Record store not open");
	}

	public static String[] listRecordStores() {
		return null;
	}

	public static RecordStore openRecordStore(String recordStoreName, boolean createIfNecessary) throws RecordStoreException, RecordStoreFullException, RecordStoreNotFoundException {
		throw new RecordStoreException("Record store not supported");
	}

	public static RecordStore openRecordStore(String recordStoreName, boolean createIfNecessary, int authmode, boolean writable) throws RecordStoreException, RecordStoreFullException, RecordStoreNotFoundException {
		throw new RecordStoreException("Record store not supported");
	}

	public static RecordStore openRecordStore(String recordStoreName, String vendorName, String suiteName) throws RecordStoreException, RecordStoreNotFoundException {
		throw new RecordStoreException("Record store not supported");
	}
}
