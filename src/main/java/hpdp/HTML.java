package hpdp;

import java.util.List;
import java.util.ArrayList;

import hpdp.Layout;


public class HTML{

	private boolean exposed;

	private List<Layout> layouts;
	public String exposedHTML;					// TO-DO change to private

	public HTML(){
		exposed = false;
		exposedHTML = null;


	}


	public void expose(){

		if (exposed == false){

		}

		exposed = true;
	}

}