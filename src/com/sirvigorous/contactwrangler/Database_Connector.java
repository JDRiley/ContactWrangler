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

public class Database_Connector{
   // database name
   private static final String DATABASE_NAME = "UserContacts";
   private static final String CONTACTS_TABLE_NAME_STRING = "Contacts";
   public static final String ID_COLLUMN_STRING = "_id";
   private SQLiteDatabase database; // for interacting with the database
   private DatabaseOpenHelper databaseOpenHelper; // creates the database

   // public constructor for DatabaseConnector
   public Database_Connector(Context context) 
   {
      // create a new DatabaseOpenHelper
      databaseOpenHelper = 
         new DatabaseOpenHelper(context, DATABASE_NAME, null, 1);
   }

   public void reset_table(){
	   open();
	   database.delete(CONTACTS_TABLE_NAME_STRING, null, null);
	   database.execSQL("DROP TABLE " + CONTACTS_TABLE_NAME_STRING);
	   databaseOpenHelper.onCreate(database);
	   close();
	   
   }
   // open the database connection
   public void open() throws SQLException 
   {
      // create or open a database for reading/writing
      database = databaseOpenHelper.getWritableDatabase();
   }

   // close the database connection
   public void close() 
   {
      if (database != null)
         database.close(); // close the database connection
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
	long rowID = database.insert(CONTACTS_TABLE_NAME_STRING, null, new_contact);
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
	database.update(CONTACTS_TABLE_NAME_STRING, edit_contact, ID_COLLUMN_STRING + "=" + i_id, null);
	close(); // close the database
} // end method updateContact

   // return a Cursor with all contact names in the database
   public Cursor getAllContacts() 
   {

      Cursor cursor =  database.query(
    		  CONTACTS_TABLE_NAME_STRING
    		  , new String[] {ID_COLLUMN_STRING, "name"}, 
         null, null, null, null, "name");

      return cursor;
   } 

   // return a Cursor containing specified contact's information 
   public Cursor getOneContact(long id) 
   {
	   open();
      Cursor cursor =  database.query(
         CONTACTS_TABLE_NAME_STRING, null, ID_COLLUMN_STRING + "=" + id, null, null, null, null);

   assert(1 != cursor.getCount());
   cursor.moveToNext();
   return cursor;
   } 

   // delete the contact specified by the given String name
   public void deleteContact(long id) 
   {
      open(); // open the database
      database.delete(CONTACTS_TABLE_NAME_STRING, ID_COLLUMN_STRING + "=" + id, null);
      close(); // close the database
   } 
   
   private class DatabaseOpenHelper extends SQLiteOpenHelper 
   {
      // constructor
      public DatabaseOpenHelper(Context context, String name,
         CursorFactory factory, int version) 
      {
         super(context, name, factory, version);
      }

      // creates the contacts table when the database is created
      @Override
      public void onCreate(SQLiteDatabase db) 
      {
         // query to create a new table named contacts
         String createQuery = "CREATE TABLE " + CONTACTS_TABLE_NAME_STRING +
            "(_id integer primary key autoincrement," +
            "name TEXT, location TEXT, phone_number LONG, " +
            "rule TEXT);";
                  
         db.execSQL(createQuery); // execute query to create the database
      } 

      @Override
      public void onUpgrade(SQLiteDatabase db, int oldVersion, 
          int newVersion) 
      {
      }
   } // end class DatabaseOpenHelper
} // end class DatabaseConnector


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
