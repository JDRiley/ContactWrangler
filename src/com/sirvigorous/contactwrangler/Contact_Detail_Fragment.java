package com.sirvigorous.contactwrangler;

import android.os.Bundle;
import android.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;



/**
 * A fragment representing a single Lady detail screen. This fragment is either
 * contained in a {@link Contacts_Wrangler_Activity} in two-pane mode (on tablets) or a
 * {@link Contact_Detail_Activity} on hand-sets.
 */
public class Contact_Detail_Fragment extends Fragment {
	/**
	 * The fragment argument representing the item ID that this fragment
	 * represents.
	 */
	public static final String ARG_ITEM_ID = "item_id";

	/**
	 * The dummy content this fragment is presenting.
	 */

	

	/**
	 * Mandatory empty constructor for the fragment manager to instantiate the
	 * fragment (e.g. upon screen orientation changes).
	 */
	public Contact_Detail_Fragment() {
	}


	

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		super.onCreateView(inflater, container, savedInstanceState);
		setRetainInstance(true);
		
		
		View root_view = inflater.inflate(R.layout.contact_detail_fragment,
				container, false);
		
		if(savedInstanceState != null){
			
			set_contact(new Contact((Contacts_Wrangler_Activity)getActivity()
					, savedInstanceState.getLong(Contacts_Wrangler_Activity.ROW_ID)));
		}else{
			assert(null != M_contact);
			
		}
		
		M_name_text = (TextView)root_view.findViewById(R.id.name_text_view);
		M_location_text = (TextView)root_view.findViewById(R.id.location_text_view);
		M_phone_number_text = (TextView)root_view.findViewById(R.id.phone_number_text_view);
		M_rule_text = (TextView)root_view.findViewById(R.id.rule_text_view);
		
		set_contact(M_contact);
		return root_view;
	}
	
	final public void set_contact(Contact i_contact){
		
		M_contact = i_contact;
		M_name_text.setText(M_contact.name());
		M_location_text.setText(M_contact.location());
		M_phone_number_text.setText("" + M_contact.phone_number());
		M_rule_text.setText(M_contact.rule());
	}
	
	private TextView M_name_text;
	private TextView M_location_text;
	private TextView M_phone_number_text;
	private TextView M_rule_text;
	private Contact M_contact;

}
