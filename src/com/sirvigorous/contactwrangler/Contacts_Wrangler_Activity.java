package com.sirvigorous.contactwrangler;

import android.app.Fragment;
import android.os.Bundle;
import android.support.v4.app.ActionBarDrawerToggle;
import android.support.v4.widget.DrawerLayout;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.app.Activity;
import android.content.res.Configuration;
import android.support.v4.view.GravityCompat;

import com.sirvigorous.contactwrangler.Add_Edit_Contact_Fragment;
import com.sirvigorous.contactwrangler.Contact_List_Fragment;
/**
 * An activity representing a list of Contacts. This activity has different
 * presentations for handset and tablet-size devices. On handsets, the activity
 * presents a list of items, which when touched, lead to a
 * {@link LadyDetailActivity} representing item details. On tablets, the
 * activity presents the list of items and item details side-by-side using two
 * vertical panes.
 * <p>
 * The activity makes heavy use of fragments. The list of items is a
 * {@link Lady_List_Fragment} and the item details (if present) is a
 * {@link LadyDetailFragment}.
 * <p>
 * This activity also implements the required {@link Lady_List_Fragment.Callbacks}
 * interface to listen for item selections.
 */
public class Contacts_Wrangler_Activity extends Activity implements
		Contact_List_Fragment.Callback, Add_Edit_Contact_Fragment.Listener
		, Import_Contacts_From_Phone_Fragment.Listener
		, Processing_Manager.Callback{


	private DrawerLayout M_drawer_layout;
	private ListView M_drawer_list;
	private String[] M_navigation_menu_strings;
	
static public final String ROW_ID = "Contact_database_row_id";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		M_title = getResources().getString(R.string.app_name);
		M_drawer_title = getResources().getString(R.string.navigation);
		
		M_navigation_menu_strings 
		= getResources().getStringArray(R.array.navigation_menu_items);
		
		
		
		M_drawer_layout = (DrawerLayout)findViewById(R.id.drawer_layout);
		
		M_drawer_layout.setDrawerShadow(R.drawable.drawer_shadow, GravityCompat.START);
		M_drawer_list = (ListView)findViewById(R.id.left_drawer);
		
		M_drawer_list.setAdapter(
				new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1
						, M_navigation_menu_strings));
		
		
		M_drawer_list.setOnItemClickListener(new DrawerItemClickListener());
		
		
		
		M_drawer_toggler =  new ActionBarDrawerToggle(this, M_drawer_layout,
				R.drawable.ic_drawer, R.string.drawer_open, R.string.drawer_close) {

				/** Called when a drawer has settled in a completely closed state. */
					public void onDrawerClosed(View view) {
						super.onDrawerClosed(view);
						getActionBar().setTitle(M_title);
						invalidateOptionsMenu(); // creates call to onPrepareOptionsMenu()
					}

					/** Called when a drawer has settled in a completely open state. */
					public void onDrawerOpened(View drawerView) {
						super.onDrawerOpened(drawerView);
						getActionBar().setTitle(M_drawer_title);
						invalidateOptionsMenu(); // creates call to onPrepareOptionsMenu()
					}
		};
		
		M_drawer_layout.setDrawerListener(M_drawer_toggler);
		getActionBar().setDisplayHomeAsUpEnabled(true);
		
		
		getActionBar().setHomeButtonEnabled(true);
		
		if(savedInstanceState != null){
			return;
		}
		

		android.app.FragmentTransaction transaction = getFragmentManager().beginTransaction();
		transaction.add(R.id.main_content_frame, new Notifications_Fragment());
	
		transaction.commit();
		
		
	}
	
	void switch_main_body_fragment(Fragment i_fragment, String i_string){
		
		android.app.FragmentTransaction transaction = getFragmentManager().beginTransaction();
		transaction.replace(R.id.main_content_frame, i_fragment);
		transaction.addToBackStack(i_string);
		transaction.commit();
	}
	
	
	
	@Override
	protected void onResume(){
		super.onResume();
		

	}

	@Override
	public void add_new_contact(){

		
		switch_main_body_fragment(new Add_Edit_Contact_Fragment(), "Adding Contact");
	}
	
	
	@Override
	public void add_contacts_from_phone(){
		switch_main_body_fragment(new Import_Contacts_From_Phone_Fragment(), "Adding from phone contacts");
	}
	
	
	@Override
	public void on_contact_selected(Contact i_Contact) {


		switch_main_body_fragment(new Contact_Detail_Fragment(i_Contact), "Detail Fragment");
		
	}
	
	@Override
	public void on_add_edit_completed(Contact i_contact){
		getFragmentManager().popBackStack();
	}
	

	


	@Override
	public void alert_processing(int i_id, String i_message){
		// TODO Auto-generated method stub
		
	}

	@Override
	public void alert_end_processing(int i_id){
		// TODO Auto-generated method stub
		
	}

	@Override
	public void fragment_completed(boolean i_update_contacts){
		getFragmentManager().popBackStack();

	}
	
	
	private class DrawerItemClickListener implements ListView.OnItemClickListener {
	    @Override
	    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
	        selectItem(position);
	    }


	}

/** Swaps fragments in the main content view */
private void selectItem(int i_position ){
    // Create a new fragment and specify the planet to show based on position
    Fragment new_fragment = null;
	switch(i_position){
	case 0:
		new_fragment = new Notifications_Fragment();
		break;
	case 1:
		assert(null == "Did not implement Messages View");
		break;
	case 2:
		new_fragment = new Contact_List_Fragment();
		break;
	case 3:
		assert(null == "Did not implement Rules View");
		break;
	default:
		assert(null == "Unknown Case in Navigation Menu");
		
	}

    switch_main_body_fragment(new_fragment, M_navigation_menu_strings[i_position]);
    
    // Highlight the selected item, update the title, and close the drawer
    M_drawer_list.setItemChecked(i_position, true);
    setTitle(M_navigation_menu_strings[i_position]);
    M_drawer_layout.closeDrawer(M_drawer_list);
}

@Override
public void setTitle(CharSequence title) {
    M_title = title;
    getActionBar().setTitle(M_title);
}






	/**
	 * When using the ActionBarDrawerToggle, you must call it during
	 * onPostCreate() and onConfigurationChanged()...
	 */
	
	@Override
	protected void onPostCreate(Bundle savedInstanceState) {
	    super.onPostCreate(savedInstanceState);
	    // Sync the toggle state after onRestoreInstanceState has occurred.
	    M_drawer_toggler.syncState();
	}
	
	@Override
	public void onConfigurationChanged(Configuration newConfig) {
	    super.onConfigurationChanged(newConfig);
	    // Pass any configuration change to the drawer toggls
	    M_drawer_toggler.onConfigurationChanged(newConfig);
	}

	
	
	   

	private CharSequence M_title;

	private ActionBarDrawerToggle M_drawer_toggler;
	private CharSequence M_drawer_title;

	@Override
	 public boolean onCreateOptionsMenu(Menu menu){
		return super.onCreateOptionsMenu(menu);
	}
}



