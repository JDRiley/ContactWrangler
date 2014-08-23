package com.sirvigorous.contactwrangler;



public class Processing_Manager{


public interface Callback{

	
	public void alert_processing(int i_id, String i_message);
	
	public void alert_end_processing(int i_id);
	
};
	private static int Ms_cur_id;
	
	public int get_id(){
		return Ms_cur_id;
	}
	
	
	
}
