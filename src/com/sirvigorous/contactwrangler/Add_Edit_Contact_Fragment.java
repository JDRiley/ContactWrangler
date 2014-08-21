package com.sirvigorous.contactwrangler;


import com.sirvigorous.contactwrangler.Contact_List_Activity;

import android.os.AsyncTask;
import android.os.Bundle;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.Fragment;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.inputmethod.InputMethodManager;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.app.Activity;

public class Add_Edit_Contact_Fragment extends Fragment {

	private Spinner M_rule_choice_spinner;
	private ArrayAdapter<String> M_rule_spinner_adapter;
	private EditText M_name_edit_text;
	private EditText M_location_met_edit_text;
	private EditText M_phone_number_edit_text;
	private String M_selected_rule;
	private long M_phone_number = 0;
	
	private Contact M_lady_contact;
	
	 public interface Listener{
	      // called after edit completed so contact can be redisplayed
	      public void on_add_edit_completed(Contact i_lady_contact);
	 }
	 
	 private Listener M_listener;
	 
	
       
	
	private View M_view;
	@Override
	public View onCreateView(
			LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		super.onCreateView(inflater, container, savedInstanceState);
		setRetainInstance(true); // save fragment across config changes
		
		M_view = 
	     inflater.inflate(R.layout.add_edit_contact_fragment, container, false);
		
		initiate_text_fields();
		initiate_spinner();
		

		
		return M_view;
	  
	}
	
	final private void initiate_text_fields(){
		M_name_edit_text = (EditText)M_view.findViewById(R.id.name_edit_test);
		M_location_met_edit_text = (EditText)M_view.findViewById(R.id.location_met);
		M_phone_number_edit_text = (EditText)M_view.findViewById(R.id.phone_number_edit_text);
		

		
		Button saveContactButton = 
		         (Button) M_view.findViewById(R.id.save_contact_button);
		      saveContactButton.setOnClickListener(M_save_button_listener);
		
	}
	
	
	final private void  initiate_spinner(){
		
		M_rule_choice_spinner = (Spinner)M_view.findViewById(R.id.rule_choice_spinner);
		
		String[] rules = getResources().getStringArray(R.array.rule_name_array);

		assert(rules.length > 0);
		
		M_selected_rule = rules[0];
		
		M_rule_spinner_adapter = new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, rules);
		
		M_rule_choice_spinner.setAdapter(M_rule_spinner_adapter);
		
		AdapterView.OnItemSelectedListener item_click_listener 
			= new AdapterView.OnItemSelectedListener(){
				@Override
				public void onItemSelected(
						AdapterView<?> i_parent, View i_view, int i_pos, long i_id){
					M_selected_rule = (String) i_parent.getItemAtPosition(i_pos);
					
				}
				
				@Override 
				public void onNothingSelected(AdapterView<?> i_parent){
					
				}
			};
			
		
		
		M_rule_choice_spinner.setOnItemSelectedListener(item_click_listener);
		
	}
	
	@Override
	public void onAttach(Activity activity){
		super.onAttach(activity);
		M_listener = (Listener)activity;
		
		
	}
	
	@Override
	public void onDetach(){
	      super.onDetach();
	      M_listener = null;
	}
	
OnClickListener M_save_button_listener = new OnClickListener(){
	@Override
	public void onClick(View i_view){
		boolean error = false;
		try{
			String name = M_name_edit_text.getText().toString().trim();
		
		System.out.println(name);
		String phone_string = M_phone_number_edit_text.getText().toString();
		M_phone_number = Long.parseLong(phone_string);
		
		System.out.println(M_phone_number);
		String location_met = M_location_met_edit_text.getText().toString().trim();
		System.out.println(location_met);
		
		
		error |= (0 == name.length());
		
		System.out.println(M_selected_rule);
		}catch(Throwable e){
			error = true;
		}
		if(!error){
            // AsyncTask to save contact, then notify listener 
            AsyncTask<Object, Object, Object> save_contact_task = 
               new AsyncTask<Object, Object, Object>() 
               {
                  @Override
                  protected Object doInBackground(Object... params) 
                  {
                     save_contact(); // save contact to the database
                     return null;
                  } 
      
                  @Override
                  protected void onPostExecute(Object result) 
                  {
                     // hide soft keyboard
                     InputMethodManager imm = (InputMethodManager) 
                        getActivity().getSystemService(
                           Context.INPUT_METHOD_SERVICE);
                     imm.hideSoftInputFromWindow(
                        getView().getWindowToken(), 0);

                     M_listener.on_add_edit_completed(M_lady_contact);
                  } 
               }; // end AsyncTask
               
            // save the contact to the database using a separate thread
               save_contact_task.execute((Object[]) null); 
         } 
         else // required contact name is blank, so display error dialog
         {
            DialogFragment errorSaving = 
               new DialogFragment()
               {
                  @Override
                  public Dialog onCreateDialog(Bundle savedInstanceState)
                  {
                     AlertDialog.Builder builder = 
                        new AlertDialog.Builder(getActivity());
                     builder.setMessage(R.string.error_saving);
                     builder.setPositiveButton(R.string.ok, null);                     
                     return builder.create();
                  }               
               };
            
            errorSaving.show(getFragmentManager(), "error saving contact");
         } 
      } // end method onClick
		
		
	};


private void save_contact(){
	// get DatabaseConnector to interact with the SQLite database
	
	
//	private Spinner M_rule_choice_spinner;
//	private ArrayAdapter<String> M_rule_spinner_adapter;

	if(M_lady_contact == null){
		// insert the contact information into the database
		M_lady_contact = new Contact((Contact_List_Activity)getActivity()
				, M_name_edit_text.getText().toString(),
				M_location_met_edit_text.getText().toString(),
				M_phone_number,
				(String)M_rule_choice_spinner.getSelectedItem());
	}
	
	M_lady_contact.update_to_database();
	
} // end method saveContact



}

