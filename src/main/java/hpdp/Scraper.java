package hpdp;


import hpdp.storage.Storage;

import java.io.IOException;
import java.util.List;
import java.util.ArrayList;


public class Scraper{

	private Storage storage = null;
	public List<String[]> data = null;
	String filePath = null;


	public Scraper(){
		storage = new Storage();
		storage.setRead(true);
		data = new ArrayList<>();


	}

	public void filePath(String filePath){
		this.filePath = filePath;
	}


	public void scrape() throws IOException {
		storage.newFile(filePath);

		String line = "";
		while ((line = storage.readLine()) != null){
			String vals[] = line.split(",");
			data.add(vals);
		}
	}

	// get different data in an index
	public List<String[]> getUniqueDataByIndex(List<String[]> data, int index){
		List<String[]> uniqueData = new ArrayList<>();
		boolean exists = false;


		for (String[] dataPoint : data){
			for (String[] uniqueDataPoint : uniqueData) {
					if (dataPoint[index].equals(uniqueDataPoint[index])) {
						exists = true;
						break;
					}
			}
			if (exists == false){
				uniqueData.add(dataPoint);
			}
			exists = false;
		}

		return uniqueData;
	}


	// Aggregate data when key is same.
	public List<List> getUniqueDataByKey(List<String[]> data, int index){
		List<List> uniqueDataLists = new ArrayList<>();
		boolean exists = false;

		// Load keys
		for (String[] dataPoint : data) {
			exists = false;
			for (List<String[]> uniqueDataList : uniqueDataLists) {
				for (String[] uniqueDataPoint : uniqueDataList) {
					if (dataPoint[index].equals(uniqueDataPoint[index])) {
						exists = true;
						break;
					}
				}
			}
			if (exists == false) {
				List<String[]> newUniqueData = new ArrayList<>();
				newUniqueData.add(dataPoint);
			//	////System.out.println("DA: " + dataPoint[0]);
				uniqueDataLists.add(newUniqueData);
			}
		}

		for (List<String[]> uniqueDataList : uniqueDataLists) {

			for (String[] dataPoint : data) {
				exists = false;
				for (String[] uniqueDataPoint : uniqueDataList) {
					if (dataPoint.equals(uniqueDataPoint)) {
						exists = true;
						break;
					}
				}
				if (exists == false) {
					String[] keyData = uniqueDataList.get(0);
					if (keyData[index].equals(dataPoint[index])) {
						uniqueDataList.add(dataPoint);
						//////System.out.println("D2A: " + dataPoint[0]);
					}
				}
			}

		}




		return uniqueDataLists;
	}


	// Get minimum time from data using key
	public Time getMinTimeFromKey(List<String[]> data, int index){
		Time minTime = new Time();
		Time comparisonTime = null;

		for (String[] dataPoint : data) {
			if (comparisonTime == null) {
				minTime =  Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));
				comparisonTime = Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));

			}
			else{
				comparisonTime = Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));
				if (comparisonTime.timestamp < minTime.timestamp){
					minTime = comparisonTime;

				}
			}

		}

		return minTime;
	}

	public Time getMaxTimeFromKey(List<String[]> data, int index){
		Time maxTime = new Time();
		Time comparisonTime = null;

		for (String[] dataPoint : data) {
			if (comparisonTime == null) {
				maxTime =  Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));
				comparisonTime = Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));
			}
			else{
				comparisonTime = Time.timeFromTimestamp((Long.parseLong(dataPoint[index])));
				if (comparisonTime.timestamp > maxTime.timestamp){
					maxTime = comparisonTime;

				}
			}

		}

		return maxTime;
	}





}