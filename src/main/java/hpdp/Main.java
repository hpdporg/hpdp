package hpdp;

import java.util.List;
import java.util.ArrayList;
import java.io.IOException;

import hpdp.*;
import hpdp.forms.*;
import hpdp.shapes.Chart.Trace;



/**
 *  Executes HPDP.
*/


public class Main {


	public static void main(String[] args){



		HPDP hpdp = new HPDP();
		Trans trans = hpdp.getTrans();
		Scraper scraper = hpdp.getScraper();
		scraper.filePath("U:\\DEVELOP\\sall\\DataStore1.csv");
		try {
			scraper.scrape();
		}
		catch (IOException e){
			e.printStackTrace();
		}

		HTML html = trans.newHTML();
		html.exposedHTML = "<html style=\"margin:0; padding:0; overflow:hidden\"><body style=\"margin:0; padding:0; overflow:hidden\"><div style=\"overflow:hidden\"><svg version=\"1.1\" baseProfile=\"full\"  style=\"position:fixed; top:0; left:0; height:100%; width:100%\" width=\"100%\" height=\"100%\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";//viewBox="0 0 100 100"
		trans.exposureLocation(Trans.ExposureLocation.HTML_FILE);
		trans.filePath("HTML1.html");

		Layout layout = html.getLayout(0);

		Header header = new Header();
		header.letters = "Statements Test Automation";
		layout.newSpaceTopology(header, layout.getSpaceRegion(0));

		Header header2 = new Header();
		header2.headerLevel = Header.HeaderLevel.LVL_2;
		header2.letters = "Runs";
		layout.newSpaceTopology(header2, layout.getSpaceRegion(0));

		Region region2 = new Region();
		layout.newSpaceTopology(region2, null);
		//region2.position[1] =layout.getSpaceRegion(0).position[0]+layout.getSpaceRegion(0).size[0];
		region2.size[1]+=50.0;

		Region region3 = new Region();
		//region3.size[1] -= 40.0;
		//region3.size[0] += 40.0;
		region3.position[1] -= 20.0;
		//region3.position[1] +=40.0;
		region3.position[0] +=90.0;
		//region3.size[1]+=80.0;

		//region3.position[1]+= 40.0;
		layout.newSpaceTopology(region3,region2);				// Chart - labels area


		Scatter scatter = new Scatter();
		scatter.jAxisLabel.rangeValueBasisIndex = 0;


		scatter.jAxisLabel.defineRangeValues(scraper.getUniqueDataByIndex(scraper.data, 0));
		scatter.iAxisLabel.defineRangeValues(scraper.data);
		scatter.iAxisLabel.setMinTime(scraper.getMinTimeFromKey(scraper.data,1));
		scatter.iAxisLabel.setMaxTime(scraper.getMaxTimeFromKey(scraper.data,1));
		scatter.jAxisLabel.defineRangeQuantities();
		scatter.iAxisLabel.defineRangeQuantities();
		scatter.quantityIncrement = scatter.jAxisLabel.quantityIncrement;		// TO-DO: Combine
		scatter.iQuantityIncrement = scatter.iAxisLabel.iQuantityIncrement;

		List<List> tracePoints = scraper.getUniqueDataByKey(scraper.data,0);

	////System.out.println("TR size: " + tracePoints.size());

		for(List<String[]> dataPointList : tracePoints){



			Trace trace = new Trace();
			scatter.newTrace(trace);
			trace.values = dataPointList;
			trace.minTime = scatter.iAxisLabel.minTime;
			trace.minTime = scatter.iAxisLabel.maxTime;
			////System.out.println("TR2 size: " + dataPointList.size());
			for (String[] dataValue : dataPointList){
				Double[] coord = new Double[2];
				coord[0] = 0.0;	// Initialize
				coord[1] = 0.0;	// Initialize
				coord[0] = scatter.iAxisLabel.iFromTimestamp(Long.parseLong(dataValue[1]));
				coord[1] = scatter.jAxisLabel.rangeQuantities.get(scatter.jAxisLabel.getRangeValueIndex(dataValue[0]));
				trace.coords.add(coord);
			}

		/*	double position = scatter.jAxisLabel.rangeQuantities.get(scatter.jAxisLabel.getRangeValueIndex(dataPoint[0]));

			////System.out.println("POs: "+position);

			trace.position[1] +=position;
*/
		}


		layout.newSpaceTopology(scatter, region3);

		Region region4 = new Region();
		layout.newSpaceTopology(region4, null);

//		region4.snap = true;
		//		region4.position[1] =region2.position[0]+region2.size[0];


		Header header3 = new Header();
		header3.headerLevel = Header.HeaderLevel.LVL_2;
		header3.letters = "Input Data Variations";
	layout.newSpaceTopology(header3, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong


		/*
		Header header4 = new Header();
		header4.headerLevel = Header.HeaderLevel.LVL_2;
		header4.letters = "Categories";
		layout.newSpaceTopology(header4, region2);

		Header header5 = new Header();
		header5.headerLevel = Header.HeaderLevel.LVL_2;
		header5.letters = "Coverage Ratio";
		layout.newSpaceTopology(header5, region2);*/


		trans.expose();
	}




}

