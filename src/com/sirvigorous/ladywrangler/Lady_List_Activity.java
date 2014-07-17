package com.sirvigorous.ladywrangler;

import android.support.v4.app.FragmentTransaction;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.view.Menu;
import android.view.MenuItem;

/**
 * An activity representing a list of Ladies. This activity has different
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
public class Lady_List_Activity extends FragmentActivity implements
		Lady_List_Fragment.Callbacks {



	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lady_list);

	}
	@Override
	public boolean onCreateOptionsMenu(Menu i_menu){
		super.onCreateOptionsMenu(i_menu);
		
		getMenuInflater().inflate(R.menu.lady_list_menu, i_menu);
		return true;
	}
	
	/**
	 * Callback method from {@link Lady_List_Fragment.Callbacks} indicating that
	 * the item with the given ID was selected.
	 */
	
	
	
	public void add_new_lady_contact(MenuItem i_menu_item){
		int menu_id = i_menu_item.getItemId();
		
		System.out.print(menu_id);
		Add_Edit_Lady_Fragment add_edit_lady_frag = new Add_Edit_Lady_Fragment();
		
		android.app.FragmentTransaction transaction = getFragmentManager().beginTransaction();
		transaction.replace(R.id.main_body_frame, add_edit_lady_frag);
		transaction.addToBackStack("Adding Contact");
		transaction.commit();
		
	}
	
	
	
	
	@Override
	public void onItemSelected(String id) {

			// In single-pane mode, simply start the detail activity
			// for the selected item ID.
			Intent detailIntent = new Intent(this, LadyDetailActivity.class);
			detailIntent.putExtra(LadyDetailFragment.ARG_ITEM_ID, id);
			startActivity(detailIntent);
		
	}
}
