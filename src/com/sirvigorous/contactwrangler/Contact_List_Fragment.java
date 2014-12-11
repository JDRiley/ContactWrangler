package com.sirvigorous.contactwrangler;


import com.sirvigorous.contactwrangler.Database_Connector;
import com.sirvigorous.contactwrangler.Contact;
import com.sirvigorous.contactwrangler.Contacts_Wrangler_Activity;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.app.ListFragment;
import android.database.Cursor;

import android.view.View;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;


import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
/**
 * A list fragment representing a list of Ladies. This fragment also supports
 * tablet devices by allowing list items to be given an 'activated' state upon
 * selection. This helps indicate which item is currently being viewed in a
 * {@link LadyDetailFragment}.
 * <p>
 * Activities containing this fragment MUST implement the {@link Lady_List_Callback}
 * interface.
 */
public class Contact_List_Fragment extends ListFragment {



/**
	 * The fragment's current callback object, which is notified of list item
	 * clicks.
	 */


	/**
	 * The current activated item position. Only used on tablets.
	 */
	
	private SimpleCursorAdapter M_contact_adapter;
	/**
	 * A callback interface that all activities containing this fragment must
	 * implement. This mechanism allows activities to be notified of item
	 * selections.
	 */
	public interface Callback{
		/**
		 * Callback for when an item has been selected.
		 */
		public void on_contact_selected(Contact i_lady_contact);
		
		public void add_contacts_from_phone();
		
		public void add_new_contact();

		
	}

	private Callback M_listener;
	private ListView M_list_view;
	private OnItemClickListener M_list_view_listener = new OnItemClickListener() 
	   {
	      @Override
	      public void onItemClick(AdapterView<?> parent, View view, 
	         int i_position, long id){
	    	  
	    	  Cursor cursor = M_contact_adapter.getCursor();
	    	  cursor.moveToPosition(i_position);
	    	  M_listener.on_contact_selected(new Contact((Contacts_Wrangler_Activity)getActivity(), cursor.getInt(
	    			  cursor.getColumnIndex(Database_Connector.ID_COLLUMN_STRING))));
	      } 
	   }; // end viewContactListener

	/**
	 * Mandatory empty constructor for the fragment manager to instantiate the
	 * fragment (e.g. upon screen orientation changes).
	 */
	   
   
	   
	public Contact_List_Fragment() {

	


	
	}
	

	

	@Override
	public void onViewCreated(View view, Bundle savedInstanceState) {
		super.onViewCreated(view, savedInstanceState);

		setRetainInstance(true);
		setHasOptionsMenu(true);
		setEmptyText(getResources().getString(R.string.loading_contacts));
		M_list_view = getListView();
		M_list_view.setOnItemClickListener(M_list_view_listener);
		M_list_view.setChoiceMode(ListView.CHOICE_MODE_SINGLE);
		
		String[] name_collumn = new String[] {"name"};
		int[] id_mapping = new int[] {android.R.id.text1};
		
		
		
		M_contact_adapter 
		= new SimpleCursorAdapter(getActivity()
				, android.R.layout.simple_list_item_activated_1, null
				, name_collumn, id_mapping, 0);
		
		
		setListAdapter(M_contact_adapter);
	}

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);

		// Activities containing this fragment must implement its callbacks.
		if (!(activity instanceof Callback)) {
			throw new IllegalStateException(
					"Activity must implement fragment's callbacks.");
		}

		M_listener = (Callback)activity;
	}

	@Override
	public void onDetach() {
		super.onDetach();

		// Reset the active callbacks interface to the dummy implementation.
		M_listener = null;
	}


	@Override
	public void onSaveInstanceState(Bundle outState) {
		super.onSaveInstanceState(outState);
	}
	
	@Override
	public void onResume(){
		super.onResume();
		update_contact_list();
	}
	
	
	   // performs database query outside GUI thread
	   private class Get_Contacts_Task extends AsyncTask<Object, Object, Cursor>{
	      Database_Connector database_connector = 
	         new Database_Connector(getActivity());

	      // open database and return Cursor for all contacts
	      @Override
	      protected Cursor doInBackground(Object... params)
	      {
	         database_connector.open();
	         return database_connector.getAllContacts(); 
	      } 

	      // use the Cursor returned from the doInBackground method
	      @Override
	      protected void onPostExecute(Cursor result){
	    	  result.moveToPosition(-1);
	    	  boolean empty = true;
	    	  while(result.moveToNext()){
	    		  empty = false;
	    		  System.out.println("Name: " + result.getString(1));
	    	  }
	    	  
	    	  if(empty){
	    		  System.out.println("Empty Cursor");
	    	  }
	    	  result.moveToPosition(-1);
	    	  setEmptyText(getResources().getString(R.string.no_contacts));
	         M_contact_adapter.changeCursor(result); // set the adapter's Cursor
	         database_connector.close();
	         
	      } 
	   } // end class GetContactsTask

	   // when fragment stops, close Cursor and remove from contactAdapter 
	   @Override
	   public void onStop() 
	   {
	      Cursor cursor = M_contact_adapter.getCursor(); // get current Cursor
	      M_contact_adapter.changeCursor(null); // adapter now has no Cursor
	      
	      if (cursor != null) 
	         cursor.close(); // release the Cursor's resources
	      
	      super.onStop();
	   } 


	
	   
	   // update data set
	   public void update_contact_list(){
		   setEmptyText(getResources().getString(R.string.loading_contacts));
	      new Get_Contacts_Task().execute((Object[]) null);
	   }
	   
	   @Override
	   public void onCreateOptionsMenu(Menu menu, MenuInflater i_inflater){
		   
		   i_inflater.inflate(R.menu.contact_list_menu, menu);	
		   super.onCreateOptionsMenu(menu, i_inflater);
	      
	   }

	   // handle choice from options menu
	   @Override
	   public boolean onOptionsItemSelected(MenuItem item){
	      switch (item.getItemId()){
	         case R.id.action_add_new_contact:
	            M_listener.add_new_contact();
	            return true;
	         case R.id.add_test:
	        	 add_test();
	        	 update_contact_list();
	        	 return true;
	         case R.id.clear_contacts:
	        	 clear_contacts();
	        	 update_contact_list();
	        	 return true;
	         case R.id.action_import_contacts_from_phone:
	        	 M_listener.add_contacts_from_phone();
	        	 return true;
	      }
	      
	      return super.onOptionsItemSelected(item); // call super's method
	   }
	   
		void clear_contacts(){
			System.out.println("Unimplemented");
			
		}
		public void add_test(){
			Database_Connector dc = new Database_Connector(getActivity());
			dc.reset_table();
			String[] rules = getResources().getStringArray(R.array.rule_name_array);
			
			
			new Contact((Contacts_Wrangler_Activity)getActivity(), "Adessa", "Theta Xi", 3017170839l, rules[0])
				.update_to_database();
			
			
			new Contact((Contacts_Wrangler_Activity)getActivity(), "Jasmine", "Other Xi", 15555555554l, rules[0])
				.update_to_database();;
			
			new Contact((Contacts_Wrangler_Activity)getActivity(), "Danielle", "House Party", 2024576288l, rules[1])
				.update_to_database();;
			
			new Contact((Contacts_Wrangler_Activity)getActivity(), "Tamera", "Planet Xenon", 7647418799l, rules[2])
				.update_to_database();
			
			update_contact_list();
				
		}
	
}
