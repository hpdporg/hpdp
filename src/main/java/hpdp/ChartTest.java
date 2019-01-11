package hpdp;

import hpdp.forms.Header;
import hpdp.forms.Scatter;
import hpdp.forms.SummaryTable;
import hpdp.shapes.Chart.Trace;

import java.io.IOException;
import java.util.List;

public class ChartTest {



    public void runTest(){



        HPDP hpdp = new HPDP();
        Trans trans = hpdp.getTrans();
        Scraper scraper = hpdp.getScraper();
        scraper.filePath("DataStore2.csv");
        try {
            scraper.scrape();
        }
        catch (IOException e){
            e.printStackTrace();
        }


        HTML html = trans.newHTML();
        html.exposedHTML = "<html style=\"margin:0; padding:0; overflow:hidden\">";//<body style=\"margin:0; padding:0; overflow:hidden\"><div style=\"overflow:hidden;position:fixed;height:100%; width:100%\"><svg version=\"1.1\" baseProfile=\"full\"  style=\" top:0; left:0;width:100%;height:100%;\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";//viewBox="0 0 100 100"

        html.exposedHTML +="<body style=\"margin:0; padding:0; overflow:hidden\"><div style=\"overflow:hidden;position:fixed;height:100%; width:100%\"><svg version=\"1.1\" baseProfile=\"full\"  style=\" top:0; left:0;width:100%;height:100%;\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";//viewBox="0 0 100 100"

/*		html.exposedHTML +="<body style=\"margin:0; padding:0; \n" +
				"overflow:hidden\"><div style=\"overflow:scroll;width:100%;height:100%\"><svg version=\"1.1\" \n" +
				"baseProfile=\"full\"  viewbox=\"0 0 800 1100\"  preserveAspectRatio=\"xMidYMid meet\" \n" +
				"xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";*/
        trans.exposureLocation(Trans.ExposureLocation.HTML_FILE);
        trans.filePath("HTML1.html");

        Layout layout = html.getLayout(0);

        Header header = new Header();
        header.letters = "Title";
        layout.newSpaceTopology(header, layout.getSpaceRegion(0));

        Header header2 = new Header();
        header2.headerLevel = Header.HeaderLevel.LVL_2;
        header2.letters = "Sub-header";
        layout.newSpaceTopology(header2, layout.getSpaceRegion(0));

        Region region2 = new Region();
        layout.newSpaceTopology(region2, null);
        //region2.position[1] =layout.getSpaceRegion(0).position[0]+layout.getSpaceRegion(0).size[0];
        region2.size[1]+=85.0;

        Region region3 = new Region();
        //region3.size[1] -= 40.0;
        //region3.size[0] += 40.0;
        region3.position[1] -= 55.0;
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
        scatter.jAxisLabel.linkPath = "";
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
            //	System.out.println("Trace coord size: " + trace.coords.size());
            //	System.out.println("Vals size: " + trace.values.size());

            trans.sortTraceCoords(trace,0);

		/*	double position = scatter.jAxisLabel.rangeQuantities.get(scatter.jAxisLabel.getRangeValueIndex(dataPoint[0]));

			////System.out.println("POs: "+position);

			trace.position[1] +=position;
*/
        }


        layout.newSpaceTopology(scatter, region3);


        Region summaryTable1Region = new Region();
        //region3.size[1]+= 40.0;
        //region3.size[0] += 40.0;
        summaryTable1Region.position[1] -= 30.0;
        //region3.position[1] +=40.0;
        //summaryTable1Region.position[0] += 0.0;// +=90.0;
        //region3.size[1]+=80.0;

        //region3.position[1]+= 40.0;
        //	layout.newSpaceTopology(summaryTable1Region,region2);				// summaryTable1Region area

        int passCount = scraper.getCountByKeyValue(scraper.data,2,"PASS");
        int failCount = scraper.getCountByKeyValue(scraper.data,2,"FAIL");
        int inProgressCount = scraper.getCountByKeyValue(scraper.data,2,"IN PROGRESS");
        int brokenCount = scraper.getCountByKeyValue(scraper.data,2,"BROKEN");
        int notStartedCount = scraper.getCountByKeyValue(scraper.data,2,"NOT STARTED");


        SummaryTable summaryTable = new SummaryTable();
        summaryTable.table.newRow("PASS", "FAIL", "IN PROGRESS", "BROKEN", "NOT STARTED");
        summaryTable.table.newRow(String.valueOf(passCount), String.valueOf(failCount), String.valueOf(inProgressCount), String.valueOf(brokenCount), String.valueOf(notStartedCount));

        layout.newSpaceTopology(summaryTable, region3);//layout.getSpaceRegion(0));//region3);//			// This is wrong


        Region region4 = new Region();
        layout.newSpaceTopology(region4, null);
        //region4.position[1] -= 90.0;
//		region4.snap = true;
        //		region4.position[1] =region2.position[0]+region2.size[0];
        //	region4.size[1]+=10.0;
		/*


		//region3.position[1] +=40.0;
		region4.position[0] +=90.0;*/

        Header header3 = new Header();
        header3.headerLevel = Header.HeaderLevel.LVL_2;
        header3.letters = "Sub-header 2";
        header3.position[1] -=30.0;
        layout.newSpaceTopology(header3, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong


        int lastPassCount = 0;
        int lastFailCount =0;
        int lastInProgressCount =0;
        int lastBrokenCount  =0;
        int lastNotStartedCount  =0;

        for(List<String[]> dataPointList : tracePoints) {

            if ((dataPointList.get(dataPointList.size()-1)[2]).equals("PASS")){

                lastPassCount += 1;


            }
            else if ((dataPointList.get(dataPointList.size()-1)[2]).equals("FAIL")){
                lastFailCount += 1;
            }
            else if ((dataPointList.get(dataPointList.size()-1)[2]).equals("IN PROGRESS")){
                lastInProgressCount += 1;
            }
            else if ((dataPointList.get(dataPointList.size()-1)[2]).equals("BROKEN")){
                lastBrokenCount += 1;
            }
            else if ((dataPointList.get(dataPointList.size()-1)[2]).equals("NOT STARTED")){
                lastNotStartedCount += 1;
            }


        }

        SummaryTable lastSummaryTable = new SummaryTable();
        lastSummaryTable.table.newRow("PASS", "FAIL", "IN PROGRESS", "BROKEN", "NOT STARTED");
        lastSummaryTable.table.newRow(String.valueOf(lastPassCount), String.valueOf(lastFailCount), String.valueOf(lastInProgressCount), String.valueOf(lastBrokenCount), String.valueOf(lastNotStartedCount));

        lastSummaryTable.position[1] -= 0.0;

        lastSummaryTable.position[0] += 90.0;

        layout.newSpaceTopology(lastSummaryTable, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong


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
	/*	while (true) {
			try {
				scraper.filePath("DataStore1.csv");
				scraper.scrape();
			}
			catch (IOException e){
				e.printStackTrace();
			}
			trans.expose();
			try {
				Thread.sleep(5000);
			}catch (Exception e){
				e.printStackTrace();
			}
		}*/

    }


}
