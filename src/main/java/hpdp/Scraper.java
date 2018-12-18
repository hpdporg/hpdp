package hpdp;


import hpdp.storage.Storage;

import java.io.IOException;
import java.util.List;
import java.util.ArrayList;


public class Scraper{

	private Storage storage = null;
	public List<String[]> data = null;


	public Scraper(){
		storage = new Storage();
		storage.setRead(true);
		data = new ArrayList<>();


	}


	public void scrape() throws IOException {
		storage.newFile("DataStore1.csv");

		String line = "";
		while ((line = storage.readLine()) != null){
			String vals[] = line.split(",");
			data.add(vals);
		}
	}




}