// DatabaseConnector.java
// Provides easy connection and creation of UserContacts database.
package com.sirvigorous.contactwrangler;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.os.Message;
import android.telephony.SmsMessage;

public class Database_Connector{
// database name
private static final String DATABASE_NAME = "UserContacts";
private static final String CONTACTS_TABLE_NAME_STRING = "Contacts";
private static final String MESSAGE_TABLE_NAME_STRING = "Messages";
public static final String ID_COLLUMN_STRING = "_id";
public static final String RULE_TABLE_NAME_STR = "Rules";
private SQLiteDatabase M_database; // for interacting with the database
private DatabaseOpenHelper databaseOpenHelper; // creates the database

// public constructor for DatabaseConnector
public Database_Connector(Context context){
  // create a new DatabaseOpenHelper
	databaseOpenHelper = 
     new DatabaseOpenHelper(context, DATABASE_NAME, null, 1);
}

public void reset_table(){
   open();
   M_database.delete(CONTACTS_TABLE_NAME_STRING, null, null);
   M_database.execSQL("DROP TABLE " + CONTACTS_TABLE_NAME_STRING);
   M_database.delete(MESSAGE_TABLE_NAME_STRING, null, null);
   M_database.execSQL("DROP TABLE " + MESSAGE_TABLE_NAME_STRING);
   M_database.delete(RULE_TABLE_NAME_STR, null, null);
   M_database.execSQL("DROP TABLE " + RULE_TABLE_NAME_STR);

   databaseOpenHelper.onCreate(M_database);
   close();

}


// open the database connection
public void open() throws SQLException{
  // create or open a database for reading/writing
  M_database = databaseOpenHelper.getWritableDatabase();
 }

// close the database connection
public void close(){
  if (M_database != null)
     M_database.close(); // close the database connection
} 

// inserts a new contact in the database
public long insertContact(String i_name, String i_location
			  , long i_phone_number, String i_rule){
	ContentValues new_contact = new ContentValues();
	new_contact.put("name", i_name);
new_contact.put("location", i_location);
new_contact.put("phone_number", i_phone_number);
new_contact.put("rule", i_rule);

open(); // open the database
long rowID = M_database.insert(CONTACTS_TABLE_NAME_STRING, null, new_contact);
close(); // close the database
	return rowID;
}

//updates an existing contact in the database
public void updateContact(long i_id, String i_name, String i_location
		  , long i_phone_number, String i_rule){
	ContentValues edit_contact = new ContentValues();
	edit_contact.put("name", i_name);
edit_contact.put("location", i_location);
edit_contact.put("phone_number", i_phone_number);
edit_contact.put("rule", i_rule);

open(); // open the database
M_database.update(CONTACTS_TABLE_NAME_STRING, edit_contact, ID_COLLUMN_STRING + "=" + i_id, null);
close(); // close the database
} // end method updateContact

// return a Cursor with all contact names in the database
public Cursor getAllContacts(){



  Cursor cursor =  M_database.query(
		  CONTACTS_TABLE_NAME_STRING
		  , new String[] {ID_COLLUMN_STRING, "name"}, 
     null, null, null, null, "name");

  return cursor;
} 

// return a Cursor containing specified contact's information 
public Cursor getOneContact(long id){
	Cursor cursor 
	= M_database.query(
			CONTACTS_TABLE_NAME_STRING, null, ID_COLLUMN_STRING + "=" + id
			, null, null, null, null);

	assert(1 != cursor.getCount());
	cursor.moveToNext();
	return cursor;
} 

// delete the contact specified by the given String name
public void deleteContact(long id){
  open(); // open the database
  M_database.delete(CONTACTS_TABLE_NAME_STRING, ID_COLLUMN_STRING + "=" + id, null);
  close(); // close the database
} 

public Cursor get_last_message_for_all_contacts(){
	Cursor cursor
	= M_database.query(
			true, MESSAGE_TABLE_NAME_STRING, new String[]{"_id", "sender_id", "message"}
			, null, null, null, null, null, null);
	
	
	
	return cursor;
}

public void insert_message(SmsMessage i_message){
	Cursor cursor
		= M_database.query(
				true, CONTACTS_TABLE_NAME_STRING, new String[]{ID_COLLUMN_STRING}
				, "phone_number=?", new String[]{get_phone_number_str(i_message)}
				, null, null, null, null);
	
	assert(0 != cursor.getCount());
	
	cursor.moveToPosition(0);
	
	int sender_id = cursor.getInt(0);
	
	
	ContentValues values = new ContentValues();
	values.put("sender_id", sender_id);
	values.put("state_id", 0);
	values.put("message", i_message.getMessageBody());
	
	M_database.insert(MESSAGE_TABLE_NAME_STRING, null, values);
		
		
}

public String get_phone_number_str(SmsMessage i_message){
	String number_str = i_message.getOriginatingAddress();
	if(number_str.length() == 10){
		//adding country code
		number_str = "1" + number_str;
		}
	return number_str;
}

public boolean is_phone_number_present(long i_number){
  Cursor cursor= M_database.query(true, CONTACTS_TABLE_NAME_STRING, new String[]{ID_COLLUMN_STRING}, "phone_number = " + i_number
		  , null, null, null, null, "1");

  return 0 != cursor.getCount();
}

private class DatabaseOpenHelper extends SQLiteOpenHelper{
  // constructor
  public DatabaseOpenHelper(Context context, String name,
     CursorFactory factory, int version){
     super(context, name, factory, version);
  }

  // creates the contacts table when the database is created
  @Override
  public void onCreate(SQLiteDatabase db){
     // query to create a new table named contacts
     String create_contacts_table_str = "CREATE TABLE " + CONTACTS_TABLE_NAME_STRING +
        "(_id integer primary key autoincrement," +
        "name TEXT, location TEXT, phone_number LONG, " +
        "rule TEXT);";

     String create_messages_table_str = "CREATE TABLE " + MESSAGE_TABLE_NAME_STRING +
             "(_id integer primary key autoincrement" 
             + ", sender_id INTEGER"
             + ", state_id INTEGER"
             + ", message TEXT);";

     String create_rule_table_str = "CREATE TABLE " 
    		 + RULE_TABLE_NAME_STR 
    		 + "(_id integer primary key autoincrement"
    		 + ", rule_name TEXT"
    		 + ", rule_text TEXT);";


     db.execSQL(create_contacts_table_str); // execute query to create the database
     db.execSQL(create_messages_table_str);
     db.execSQL(create_rule_table_str);
  }



  @Override
  public void onUpgrade(SQLiteDatabase db, int oldVersion, 
      int newVersion){
  }
} // end class DatabaseOpenHelper
} // end class DatabaseConnector


