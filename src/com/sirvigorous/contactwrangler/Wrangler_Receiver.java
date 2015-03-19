package com.sirvigorous.contactwrangler;


import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import android.os.Bundle;
import android.telephony.SmsMessage;
import android.widget.Toast;


public class Wrangler_Receiver extends BroadcastReceiver{


private Context M_context;

@Override
public void onReceive(Context context, Intent intent){
	M_context = context;
	Database_Connector database_connector = new Database_Connector(context);
	database_connector.open();
	Bundle bundle = intent.getExtras();
    SmsMessage[] recievedMsgs = null;
    String str = "";
    if (bundle != null){

        Object[] pdus = (Object[]) bundle.get("pdus");
        recievedMsgs = new SmsMessage[pdus.length];
        assert(1 == pdus.length);
        for (int i=0; i < pdus.length ; i++){
        	SmsMessage cur_message
        	 = recievedMsgs[i] = SmsMessage.createFromPdu((byte[])pdus[i]);
        	String message_text = cur_message.getMessageBody().toString();
        	
        	 
            str += "SMS from " + cur_message.getOriginatingAddress()
            		+ " :" + message_text;
            String number_str = cur_message.getOriginatingAddress();
            if(number_str.length() == 10){
            	//adding country code
            	number_str = "1" + number_str;
            }
            System.out.println("Number: " + number_str);
            long number = Long.parseLong(number_str);
            
            
           
            	if(database_connector.is_phone_number_present(number)){
            	System.out.println("Blocked message from number: " + number);
            	add_message_to_database(cur_message);
            	abortBroadcast();
            }else{
            	Toast.makeText(context, str, Toast.LENGTH_SHORT).show();
            	
            }
        }	

        

    }


	System.out.println("Recieving");

}

private void add_message_to_database(SmsMessage i_message){
	Database_Connector database_connector 
	= new Database_Connector(M_context);
	
	//TODO: Somehow notify running activity that a message has been received
	database_connector.open();
	database_connector.insert_message(i_message);
	database_connector.close();
	
	
	
	
}


}
