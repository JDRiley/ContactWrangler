package com.sirvigorous.ladywrangler;

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

	/**
	 * Whether or not the activity is in two-pane mode, i.e. running on a tablet
	 * device.
	 */
	private boolean mTwoPane;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lady_list);

	
		
		if (findViewById(R.id.lady_detail_container) != null) {
			// The detail container view will be present only in the
			// large-screen layouts (res/values-large and
			// res/values-sw600dp). If this view is present, then the
			// activity should be in two-pane mode.
			mTwoPane = true;

			// In two-pane mode, list items should be given the
			// 'activated' state when touched.
			((Lady_List_Fragment) getSupportFragmentManager().findFragmentById(
					R.id.lady_list)).setActivateOnItemClick(true);
		}

		// TODO: If exposing deep links into your app, handle intents here.
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
		
	}
	
	@Override
	public void onItemSelected(String id) {
		if (mTwoPane) {
			// In two-pane mode, show the detail view in this activity by
			// adding or replacing the detail fragment using a
			// fragment transaction.
			Bundle arguments = new Bundle();
			arguments.putString(LadyDetailFragment.ARG_ITEM_ID, id);
			LadyDetailFragment fragment = new LadyDetailFragment();
			fragment.setArguments(arguments);
			getSupportFragmentManager().beginTransaction()
					.replace(R.id.lady_detail_container, fragment).commit();

		} else {
			// In single-pane mode, simply start the detail activity
			// for the selected item ID.
			Intent detailIntent = new Intent(this, LadyDetailActivity.class);
			detailIntent.putExtra(LadyDetailFragment.ARG_ITEM_ID, id);
			startActivity(detailIntent);
		}
	}
}
