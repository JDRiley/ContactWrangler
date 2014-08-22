package com.sirvigorous.contactwrangler;

import android.R.integer;
import android.app.ListFragment;
import android.content.CursorLoader;
import android.content.Loader;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.app.LoaderManager.LoaderCallbacks;
import android.provider.ContactsContract;
import android.provider.ContactsContract.Contacts;
import android.widget.SimpleCursorAdapter;


public class Import_Contacts_From_Phone_Fragment extends ListFragment{
	

	public interface Callback{
		
	}

	private ListView M_list_view;
	
	private Callback M_listener;
	
	private SimpleCursorAdapter M_contact_adapter;
	
	private static final String[] Ms_projection
	= {
		Contacts._ID, Contacts.LOOKUP_KEY, Contacts.DISPLAY_NAME_PRIMARY
	};
	
	private static final int CONTACT_ID_INDEX = 0;
	private static final int LOOKUP_KEY_INDEX = 1;
	
	private AdapterView.OnItemClickListener M_list_view_listener 
		= new AdapterView.OnItemClickListener() 
	   {
	      @Override
	      public void onItemClick(AdapterView<?> parent, View view, 
	         int i_position, long id){
	    	  
//	    	  Cursor cursor = M_contact_adapter.getCursor();
//	    	  cursor.moveToPosition(i_position);
//	    	  //this not right. multiple selection so should just add it to list of selected
//	    	  M_listener.on_contact_selected(new Contact((Contact_List_Activity)getActivity(), cursor.getInt(
//	    			  cursor.getColumnIndex(Database_Connector.ID_COLLUMN_STRING))));
	      } 
	   }; //end M_list_view_listener
	
	
	private LoaderCallbacks<Cursor> M_loader_callback 
	= new LoaderCallbacks<Cursor>(){


		@Override
		public Loader<Cursor> onCreateLoader(int i_loader_id, Bundle i_args){
			// TODO Auto-generated method stub
			return new CursorLoader(
					getActivity(), Contacts.CONTENT_URI, Ms_projection
					, Contacts.HAS_PHONE_NUMBER , null, Contacts.DISPLAY_NAME_PRIMARY);
		}

		@Override
		public void onLoadFinished(Loader<Cursor> i_loader, Cursor i_cursor){
			M_contact_adapter.swapCursor(i_cursor);
			
		}

		@Override
		public void onLoaderReset(Loader<Cursor> i_loader){
			M_contact_adapter.swapCursor(null);
			
		}
		
	};
	 
	
	
	
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState) {
		//This inflates view
		super.onViewCreated(view, savedInstanceState);

		getLoaderManager().initLoader(0, null, M_loader_callback);
		
		setRetainInstance(true);
		setHasOptionsMenu(true);
		setEmptyText(getResources().getString(R.string.loading_contacts));
		M_list_view = getListView();
		M_list_view.setOnItemClickListener(M_list_view_listener);
		M_list_view.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);
		
		String[] name_collumn = new String[] {Contacts.DISPLAY_NAME_PRIMARY};
		int[] id_mapping = new int[] {android.R.id.text1};
		
		
		
		M_contact_adapter 
		= new SimpleCursorAdapter(getActivity()
				, android.R.layout.simple_list_item_activated_1, null
				, name_collumn, id_mapping, 0);
		
		
		setListAdapter(M_contact_adapter);
	}
	
	
	
}
