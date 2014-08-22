package com.sirvigorous.contactwrangler;
import android.app.Fragment;


import android.os.Bundle;
import android.app.Activity;

import com.sirvigorous.contactwrangler.Add_Edit_Contact_Fragment;
import com.sirvigorous.contactwrangler.Contact_List_Fragment;
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
public class Contact_List_Activity extends Activity implements
		Contact_List_Fragment.Callback, Add_Edit_Contact_Fragment.Listener
		, Import_Contacts_From_Phone_Fragment.Callback{


	private Contact_List_Fragment M_contact_list_fragment;


static public final String ROW_ID = "Contact_database_row_id";


	void switch_main_body_fragment(Fragment i_fragment, String i_string){
		
		android.app.FragmentTransaction transaction = getFragmentManager().beginTransaction();
		transaction.replace(R.id.main_body_frame, i_fragment);
		transaction.addToBackStack(i_string);
		transaction.commit();
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_contact_list);
		
		if(savedInstanceState != null){
			return;
		}
		
		M_contact_list_fragment = new Contact_List_Fragment();
		
		android.app.FragmentTransaction transaction = getFragmentManager().beginTransaction();
		transaction.add(R.id.main_body_frame, M_contact_list_fragment);

		transaction.commit();
		
		add_test();
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
		Contact_Detail_Fragment detail_fragment = new Contact_Detail_Fragment(i_Contact);

		switch_main_body_fragment(detail_fragment, "Detail Fragment");
		
	}
	
	@Override
	public void on_add_edit_completed(Contact i_contact){
		getFragmentManager().popBackStack();
		
	}
	
	@Override
	public void clear_contacts(){
		Database_Connector dc = new Database_Connector(this);
		dc.reset_table();
	}
	
	@Override
	public void add_test(){
		Database_Connector dc = new Database_Connector(this);
		dc.reset_table();
		String[] rules = getResources().getStringArray(R.array.rule_name_array);
		
		
		new Contact(this, "Adessa", "Theta Xi", 3017170839l, rules[0])
			.update_to_database();
		
		
		new Contact(this, "Jasmine", "Other Xi", 2124317751l, rules[1])
			.update_to_database();;
		
		new Contact(this, "Danielle", "House Party", 2024576288l, rules[2])
			.update_to_database();;
		
		new Contact(this, "Tamera", "Planet Xenon", 7647418799l, rules[2])
			.update_to_database();
		

			
	}
}
