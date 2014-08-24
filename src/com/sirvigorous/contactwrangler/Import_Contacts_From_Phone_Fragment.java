package com.sirvigorous.contactwrangler;


import java.util.ArrayList;
















import com.sirvigorous.contactwrangler.Add_Edit_Contact_Fragment.Listener;

import android.R.anim;
import android.R.bool;
import android.R.integer;
import android.app.Activity;
import android.app.ListFragment;
import android.content.CursorLoader;
import android.content.Loader;
import android.database.Cursor;
import android.database.MatrixCursor;
import android.os.AsyncTask;
import android.os.Bundle;
import android.telephony.PhoneStateListener;
import android.util.SparseBooleanArray;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;
import android.app.LoaderManager.LoaderCallbacks;
import android.provider.ContactsContract;
import android.provider.ContactsContract.CommonDataKinds.Phone;
import android.provider.ContactsContract.Contacts;
import android.widget.SimpleCursorAdapter;
import android.provider.ContactsContract.Data;


import android.database.MatrixCursor;
public class Import_Contacts_From_Phone_Fragment extends ListFragment{
	

	public interface Listener{
		public void fragment_completed(boolean i_update_contacts);
		
		public void update_contact_list();
	};

	private ListView M_list_view;
	
	private Listener M_listener;
	private SimpleCursorAdapter M_contact_adapter;
	private ArrayList<String[]> M_contact_data_array;
	
	
	private static final String[] M_matrix_projection
	= {
		Contacts._ID, Contacts.LOOKUP_KEY, Contacts.DISPLAY_NAME_PRIMARY, Phone.NORMALIZED_NUMBER
		
		
	};
	
	
	
	
	private static final String[] M_CURSOR_PROJECTION_STRINGS
	= {
		Contacts._ID, Contacts.LOOKUP_KEY, Contacts.DISPLAY_NAME_PRIMARY
	};
	
	private static final int CONTACT_ID_INDEX = 0;
	private static final int LOOKUP_KEY_INDEX = 1;
	private static final int CONTACT_NAME_INDEX = 2;
	private static final int PHONE_NUMBER_INDEX = 3;
	
	
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState) {
		//This inflates view
		super.onViewCreated(view, savedInstanceState);

		getLoaderManager().initLoader(0, null, M_loader_callback);
		
		setRetainInstance(true);
		setHasOptionsMenu(true);
		setEmptyText(getResources().getString(R.string.loading_contacts));
		M_list_view = getListView();

		M_list_view.setFocusable(false);

		M_list_view.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);

		
		String[] name_collumn = new String[] {
				Contacts.DISPLAY_NAME_PRIMARY, Phone.NORMALIZED_NUMBER};
		int[] id_mapping = new int[] {android.R.id.text1, android.R.id.text2};
		
		
		
		M_contact_adapter 
		= new SimpleCursorAdapter(getActivity()
				, android.R.layout.simple_list_item_activated_2, null
				, name_collumn, id_mapping, 0);
		
		
		setListAdapter(M_contact_adapter);
	}
	
	
	
	
	@Override
	public void onAttach(Activity activity){
		super.onAttach(activity);
		M_listener = (Listener)getActivity();
		assert(activity instanceof Listener);
		assert(M_listener != null);
		
	}
	
	@Override
	public void onDetach(){
	      super.onDetach();
	      M_listener = null;
	}
	
	@Override
	public void onListItemClick(ListView l, View v, int i_position, long id){
		super.onListItemClick(l, v, i_position, id);
	    	  assert(l == M_list_view);
	    	  assert(M_contact_adapter.hasStableIds());
	    	  

	    	  
	    	  System.out.println(M_list_view.getCheckedItemCount() + " ");
	    	  
	      
	   } //end M_list_view_listener
	
	
	final String get_as_string(Cursor i_cursor, int i_index){
		switch(i_cursor.getType(i_index)){
		case Cursor.FIELD_TYPE_NULL:
			return "null";
		case Cursor.FIELD_TYPE_INTEGER:
			return "" + i_cursor.getInt(i_index);
		case Cursor.FIELD_TYPE_FLOAT:
			return "" + i_cursor.getFloat(i_index);
		case Cursor.FIELD_TYPE_STRING:
			return i_cursor.getString(i_index);
		}
		
		return "Type not Found";
	}
	   
	   
	private LoaderCallbacks<Cursor> M_loader_callback 
	= new LoaderCallbacks<Cursor>(){


		@Override
		public Loader<Cursor> onCreateLoader(int i_loader_id, Bundle i_args){

			return new CursorLoader(
					getActivity(), Contacts.CONTENT_URI, M_CURSOR_PROJECTION_STRINGS
					, Data.HAS_PHONE_NUMBER , null, Data.DISPLAY_NAME_PRIMARY);
		}

		@Override
		public void onLoadFinished(Loader<Cursor> i_loader, Cursor i_cursor){

			MatrixCursor temp_names_only_Cursor
			= new MatrixCursor(M_matrix_projection, i_cursor.getCount());
			
			ArrayList<String[]> contact_data
			= new ArrayList<String[]>();
			
			while(i_cursor.moveToNext()){
				String[] contact_data_array = new String[4];
				
				contact_data_array[0] = i_cursor.getString(CONTACT_ID_INDEX);
				contact_data_array[1] = i_cursor.getString(LOOKUP_KEY_INDEX);
				String display_name = i_cursor.getString(CONTACT_NAME_INDEX);
				contact_data_array[2] = display_name;
				
				
				contact_data_array[3] = "";
				contact_data.add(contact_data_array);
				temp_names_only_Cursor.addRow(contact_data_array);
			}
		
			
			
			

			M_contact_adapter.swapCursor(temp_names_only_Cursor);
			M_contact_data_array = contact_data;
			
			i_cursor.moveToPosition(-1);
			new Set_Contact_Numbers_Task().execute(new Cursor[]{i_cursor});	
		}

		@Override
		public void onLoaderReset(Loader<Cursor> i_loader){
			M_contact_adapter.swapCursor(null);
			
		}
		
	};
	 
	
	
	

	class Set_Contact_Numbers_Task extends AsyncTask<Cursor, Object, Cursor>{
	
	
	
		@Override
		protected Cursor doInBackground(Cursor... params){
			Cursor cursor = params[0];
			
			MatrixCursor filled_matrix_cursor
			= new MatrixCursor(M_matrix_projection, cursor.getCount());
			
			ArrayList<String[]> contacts_array
			= new ArrayList<String[]>();
			while(cursor.moveToNext()){
				String[] contact_data_array = new String[4];
				
				contact_data_array[0] = cursor.getString(CONTACT_ID_INDEX);
				contact_data_array[1] = cursor.getString(LOOKUP_KEY_INDEX);
				String display_name = cursor.getString(CONTACT_NAME_INDEX);
				contact_data_array[2] = display_name;
				
				Cursor phone_cursor = getActivity().getContentResolver()
				.query(Phone.CONTENT_URI, new String[]{Phone.NORMALIZED_NUMBER}
						, Phone.DISPLAY_NAME_PRIMARY + "= ?"
						, new String[]{display_name}, null);
				
				phone_cursor.moveToFirst();
				final int phone_collumn = phone_cursor.getColumnIndex(Phone.NORMALIZED_NUMBER);
				contact_data_array[3] = phone_cursor.getString(phone_collumn);
				
				filled_matrix_cursor.addRow(contact_data_array);
				contacts_array.add(contact_data_array);
				phone_cursor.close();
				
		
				
			}
			
			

			M_contact_data_array = contacts_array;
			
			return filled_matrix_cursor;

}
		@Override
		protected void onPostExecute(Cursor i_cursor){
			setEmptyText(getResources().getString(R.string.no_contacts));
			M_contact_adapter.changeCursor(i_cursor);
		}
		
		
		

		

};	
	// display this fragment's menu items
	@Override
	public void onCreateOptionsMenu(Menu menu, MenuInflater inflater){
		   
	   super.onCreateOptionsMenu(menu, inflater);
	   inflater.inflate(R.menu.import_contacts_from_phone_menu, menu);
	}
	
	// handle choice from options menu
	@Override
	public boolean onOptionsItemSelected(MenuItem item) 
	{
		   
	   switch(item.getItemId()){
	      case R.id.action_done_import_contacts:
	         import_selected_contacts();
	         return true;

	   }
	   
	   return super.onOptionsItemSelected(item); // call super's method
	}
	
	
	private void import_selected_contacts(){
		SparseBooleanArray selected_positions = M_list_view.getCheckedItemPositions();
	
		ArrayList<Contact> contacts = new ArrayList<Contact>();
		
		for(int i=0; i < M_list_view.getCount(); ++i){
			if(!selected_positions.get(i)){
				continue;
			}
			
			Contact contact
			= new Contact((Contact_List_Activity)getActivity(), get_display_name(i)
					, "" , get_number(i), "Default");
			
			contacts.add(contact);
		}
		
		
		
		 AsyncTask<Object, Object, Object> upload_contacts_task 
		 = new AsyncTask<Object, Object, Object>(){
			 
			@Override
			public Object doInBackground(Object... i_params){
				assert(i_params[0] instanceof ArrayList<?>);
				
				ArrayList<Contact> contacts = (ArrayList<Contact>)i_params[0];
				
				for(Contact contact : contacts){
					contact.update_to_database();
				}
				
				M_listener.fragment_completed(contacts.size() > 0);
				return null;
			}
			
			@Override
			public void onPostExecute(Object i_obj){
				
			}

	
		 };
		 
		 upload_contacts_task.execute(new Object[]{contacts});
	
	}
	
	private final String get_display_name(int i_position){

		
		return M_contact_data_array.get(i_position)[CONTACT_NAME_INDEX];
	}
	
	private final long get_number(int i_position){

		String num_string 
		= M_contact_data_array.get(i_position)[PHONE_NUMBER_INDEX].substring(1);
		return Long.parseLong(num_string);
	}
	
	
	
	
	
	
	
}
