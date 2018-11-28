package hpdp;

import java.util.List;
import java.util.ArrayList;


public class HPDP{

	public Scraper scraper;
	public Trans trans;


	public HPDP(){



	}


	public Trans getTrans(){
		if (trans == null){
			trans = new Trans();
		}
		return trans;
	}





}