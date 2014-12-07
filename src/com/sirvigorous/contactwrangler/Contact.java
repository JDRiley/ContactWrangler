package com.sirvigorous.contactwrangler;


import android.database.Cursor;
import android.location.Location;

import com.sirvigorous.contactwrangler.Database_Connector;
import com.sirvigorous.contactwrangler.Contacts_Wrangler_Activity;

public class Contact{

private String M_name;
private String M_location;
private long M_phone_number;
private String M_rule;
private long M_row_id = -1;
private Contacts_Wrangler_Activity M_context;

public Contact(Contacts_Wrangler_Activity i_context,
		String i_name, String i_location
		, long i_phone_number, String i_rule){

	M_context = i_context;
	M_name = i_name;
	M_location = i_location;
	M_phone_number = i_phone_number;
	M_rule = i_rule;
	
}

public Contact(Contacts_Wrangler_Activity i_context, long i_id){
	M_context = i_context;
	set_data_from_database_id(i_id);
}

private final void set_data_from_database_id(long i_id){
	Database_Connector database_connecter
	= new Database_Connector(M_context);
	Cursor cursor = database_connecter.getOneContact(i_id);
	
	
	int value_index = 0;
	
	M_row_id = cursor.getLong(value_index++);
	M_name  = cursor.getString(value_index++);
	M_location  = cursor.getString(value_index++);
	M_phone_number  = cursor.getLong(value_index++);
	M_rule = cursor.getString(value_index++);
	
	
}

public void update_to_database(){
	Database_Connector databaseConnector =
			new Database_Connector(M_context);
	
	if(M_row_id < 0){
		M_row_id = databaseConnector.insertContact(
				M_name, M_location, M_phone_number, M_rule);
	}else{
		databaseConnector.updateContact(
				M_row_id, M_name, M_location
				, M_phone_number, M_rule);
	}
}

public String name(){
	return M_name;
}

public String location(){
	return M_location;
}

public long phone_number(){
	return M_phone_number;
}

public String rule(){
	return M_rule;
}

}