package com.sirvigorous.contactwrangler;



import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.app.Activity;
import android.database.Cursor;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;

public class Messages_Fragment extends Contact_Fragment{

	ListView M_list_view;
	private View M_view;
	public Messages_Fragment(){
		
	}
	
	
	
	
	@Override
	public View onCreateView(
			LayoutInflater inflater, ViewGroup container, Bundle i_savedInstanceState){
		super.onCreateView(inflater, container, i_savedInstanceState);
		setRetainInstance(true);
		
		M_view 
		= inflater.inflate(R.layout.messages_fragment,  container, false);
		
		M_list_view 
		= (ListView)M_view.findViewById(R.id.messages_list_view);
		
		assert(null != M_list_view);
		
		M_list_view.setFocusable(false);
		M_list_view.setChoiceMode(ListView.CHOICE_MODE_SINGLE);
		
		
		String[] collumn_names
		= {"sender_id", "message"};
		
		int[] id_box_mapping
		= {android.R.id.text1, android.R.id.text2};
		
		
		M_messages_adapter
		= new SimpleCursorAdapter(
				getActivity(), android.R.layout.simple_expandable_list_item_2, null
				, collumn_names, id_box_mapping, 0);
		
		
		M_list_view.setAdapter(M_messages_adapter);
		
		update_messages();
		
		return M_view;
	}
	
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState){
		super.onViewCreated(view, savedInstanceState);
		update_messages();
	
	}
	
	@Override
	public void onAttach(Activity i_activity){
		super.onAttach(i_activity);
		
	}
	
	
	
	public void update_messages(){
		new Get_Messages_Task().execute();
	}
	
	
private class Get_Messages_Task extends AsyncTask<Object, Object, Cursor>{

	@Override
	protected Cursor doInBackground(Object...  i_params){
		
		Database_Connector database_connector
		= new Database_Connector(getActivity());
		
		database_connector.open();
		
		
		
		Cursor messages_cursor = database_connector.get_last_message_for_all_contacts();
		
	
		
		return messages_cursor;
	}
	
	@Override
	protected void onPostExecute(Cursor i_cursor){
		//only the original thread can change its views
		M_messages_adapter.changeCursor(i_cursor);
	}
}
	
	private SimpleCursorAdapter M_messages_adapter;
	
	
	
	
}
