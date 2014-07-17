package com.sirvigorous.ladywrangler;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;



/**
 * A fragment representing a single Lady detail screen. This fragment is either
 * contained in a {@link Lady_List_Activity} in two-pane mode (on tablets) or a
 * {@link LadyDetailActivity} on hand-sets.
 */
public class LadyDetailFragment extends Fragment {
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
	public LadyDetailFragment() {
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.fragment_lady_detail,
				container, false);

		// Show the dummy content as text in a TextView.
	//	if (mItem != null) {
	//		((TextView) rootView.findViewById(R.id.lady_detail))
	//				.setText(mItem.content);
	//	}

		return rootView;
	}
}
