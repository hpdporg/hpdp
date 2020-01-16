package hpdp.forms.layout;

import hpdp.*;
import hpdp.forms.*;
import hpdp.shapes.Chart.Trace;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class SummaryReport {


    public void build(HPDP hpdp, String outputFile){


        Trans trans = hpdp.getTrans();
        Scraper scraper = hpdp.getScraper();
        HTML html = trans.newHTML();
        html.exposedHTML = "<html style=\"margin:0; padding:0; overflow:hidden\">";//<body style=\"margin:0; padding:0; overflow:hidden\"><div style=\"overflow:hidden;position:fixed;height:100%; width:100%\"><svg version=\"1.1\" baseProfile=\"full\"  style=\" top:0; left:0;width:100%;height:100%;\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";//viewBox="0 0 100 100"

        html.exposedHTML +="<body style=\"margin:0; padding:0; overflow:hidden\"><img src=\"Logo.jpg\" style=\"height:46.1123;padding-right: 150px;\" /><div style=\"height:10\"></div><div style=\"overflow:scroll;height:100%; width:100%\"><svg version=\"1.1\" baseProfile=\"full\"  style=\"min-width:100%;width:1920px;top:0; left:0;\" viewBox=\"0 0 1920 1820\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";//viewBox="0 0 100 100"

/*		html.exposedHTML +="<body style=\"margin:0; padding:0; \n" +
				"overflow:hidden\"><div style=\"overflow:scroll;width:100%;height:100%\"><svg version=\"1.1\" \n" +
				"baseProfile=\"full\"  viewbox=\"0 0 800 1100\"  preserveAspectRatio=\"xMidYMid meet\" \n" +
				"xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">";*/
        trans.exposureLocation(Trans.ExposureLocation.HTML_FILE);
        trans.filePath(outputFile);

        Layout layout = html.getLayout(0);

        Header header = new Header();
        header.letters = "Statements Participant Audit";
        layout.newSpaceTopology(header, layout.getSpaceRegion(0));

        Header header2 = new Header();
        header2.headerLevel = Header.HeaderLevel.LVL_2;
        String runDate = "2019-01-09 05:23";
        header2.letters = "Test Run: " + runDate;
        layout.newSpaceTopology(header2, layout.getSpaceRegion(0));


        Region region2 = new Region();
        layout.newSpaceTopology(region2, null);
        //region2.position[1] =layout.getSpaceRegion(0).position[0]+layout.getSpaceRegion(0).size[0];
        region2.size[1]+=8.0;

        Region region3 = new Region();
        //region3.size[1] -= 40.0;
        //region3.size[0] += 40.0;
        //  region3.position[1] -= 55.0;
        //region3.position[1] +=40.0;
        region3.position[0] +=90.0;
        //region3.size[1]+=80.0;

        //region3.position[1]+= 40.0;
        layout.newSpaceTopology(region3,null);				// Chart - labels area


        //   Region summaryTable1Region = new Region();
        //region3.size[1]+= 40.0;
        //region3.size[0] += 40.0;
        //      summaryTable1Region.position[1] -= 30.0;


        CompositeTable compositeTable = new CompositeTable();
        compositeTable.table.newRow("Case");
        compositeTable.table.newRow("TTAG1809 UADA1");
        compositeTable.table.newRow("Participant");
        compositeTable.table.newRow("John Brown 182-19-1028");
        compositeTable.table.newRow("Date Range");
        compositeTable.table.newRow("2017-01-01   2017-07-01");

        layout.newSpaceTopology(compositeTable, region3);//layout.getSpaceRegion(0));//region3);//			// This is wrong





        Region region4 = new Region();
        layout.newSpaceTopology(region4, null);

        Header header3 = new Header();
        header3.headerLevel = Header.HeaderLevel.LVL_2;
        header3.letters = "Summary";
        header3.position[1] +=8.0;
        layout.newSpaceTopology(header3, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong


        SummaryTable overallSummaryTable = new SummaryTable();
        overallSummaryTable.table.newRow("Overall");
        overallSummaryTable.table.newRow("PASS");

        overallSummaryTable.position[1] += 24.0;

        overallSummaryTable.position[0] += 90.0;

        layout.newSpaceTopology(overallSummaryTable, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong



        ColorIndicator colorIndicator = new ColorIndicator();

        colorIndicator.position[1] += 3.0;

        colorIndicator.position[0] += 280.0;
        colorIndicator.legendValue = "PASS";
        layout.newSpaceTopology(colorIndicator, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong

        AreaChart areaChart = new AreaChart();
        areaChart.position[1] -= 140.0;

        areaChart.position[0]  += 50.0;//90.0;
        layout.newSpaceTopology(areaChart, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong
        areaChart.plots = new String[]{"PASS","FAIL"};

        List<List> tracePoints = new ArrayList<>();
        List<String[]> contributions = new ArrayList<>();
        contributions.add(new String[]{"FAIL"});
       /* List<String[]> beginningBalance = new ArrayList<>();
        beginningBalance.add(new String[]{"PASS"});
        List<String[]> endingBalance = new ArrayList<>();
        endingBalance.add(new String[]{"FAIL"});
        List<String[]> beginningBalanceSum = new ArrayList<>();
        beginningBalanceSum.add(new String[]{"PASS"});
        List<String[]> endingBalanceSum = new ArrayList<>();
        endingBalanceSum.add(new String[]{"FAIL"});
        List<String[]> activeLoansSum = new ArrayList<>();
        activeLoansSum.add(new String[]{"FAIL"});
        List<String[]> activeLoans = new ArrayList<>();
        activeLoans.add(new String[]{"PASS"});
*/
        tracePoints.add(contributions);
       /* tracePoints.add(beginningBalance);
        tracePoints.add(endingBalance);
        tracePoints.add(beginningBalanceSum);
        tracePoints.add(endingBalanceSum);
        tracePoints.add(activeLoansSum);
        tracePoints.add(activeLoans);*/





        ////System.out.println("TR size: " + tracePoints.size());

        double passCount = 0.0;
        double failCount = 0.0;


        int index = 0;
        for(List<String[]> dataPointList : tracePoints){



            Trace trace = new Trace();
            areaChart.newTrace(trace);
            //  trace.values = dataPointList;

            ////System.out.println("TR2 size: " + dataPointList.size());
            for (String[] dataValue : dataPointList){
                Double[] coord = new Double[2];
                coord[0] = 0.0;	// Initialize
                coord[1] = 0.0;	// Initialize
                coord[0] = (double)index;
                if (dataValue[0].equals("PASS")) {
                    coord[0] = 0.0;
                    coord[1] = 54.237;
                    passCount += 1.0;
                }
                else{
                    coord[0] = 0.0;
                    coord[1] = 0.0;
                    failCount += 1.0;
                }
                trace.coords.add(coord);
                trace.values = new ArrayList<>();
                trace.values.add(dataValue);



            }
            //	System.out.println("Trace coord size: " + trace.coords.size());
            //	System.out.println("Vals size: " + trace.values.size());


            //	double position = scatter.jAxisLabel.rangeQuantities.get(scatter.jAxisLabel.getRangeValueIndex(dataPoint[0]));

            ////System.out.println("POs: "+position);

            //	trace.position[1] +=position;
            ++index;
        }

        if (areaChart.traces.size() !=1) {
            areaChart.iQuantityIncrement = (154.173 / (areaChart.traces.size() - 1));
        }
        else{
            areaChart.iQuantityIncrement = (154.173);
        }



        SummaryTable ratioSummaryTable = new SummaryTable();
        ratioSummaryTable.table.newRow("Ratio");
        double ratioPct = passCount / (passCount+failCount);
        DecimalFormat decimalFormat = new DecimalFormat("#0.00");

        ratioSummaryTable.table.newRow(""+decimalFormat.format(ratioPct)+"% ",""+passCount+"/"+(passCount+failCount)+"");

        ratioSummaryTable.position[1] -= (areaChart.size[1]+270.0);

        ratioSummaryTable.position[0] += 90.0;

        layout.newSpaceTopology(ratioSummaryTable, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong


        Region region5 = new Region();

        layout.newSpaceTopology(region5, null);

        Header header4 = new Header();
        header4.headerLevel = Header.HeaderLevel.LVL_2;
        header4.letters = "Details";
        header4.position[1] -= 640.0;
        header4.position[1] +=8.0;
        layout.newSpaceTopology(header4, region5);//layout.getSpaceRegion(0));//region3);//			// This is wrong

        Header passHeader = new Header();
        passHeader.headerLevel = Header.HeaderLevel.LVL_3;
        passHeader.letters = "Pass";
        passHeader.position[1] = header4.position[1] + 8.0;
        passHeader.position[0] +=30.0;
        layout.newSpaceTopology(passHeader, region5);//layout.getSpaceRegion(0));//region3);//			// This is wrong




        SummaryTable detailsPassSummaryTable = new SummaryTable();
        detailsPassSummaryTable.table.newRow("Metric       ", "Expected", "Actual");
        detailsPassSummaryTable.table.newRow("Contributions", "171.18","2018.11");
        detailsPassSummaryTable.table.newRow("Beginning Balance", "171.18","2018.11");
        detailsPassSummaryTable.table.newRow("Ending Balance", "171.18","2018.11");

        detailsPassSummaryTable.position[1] = passHeader.position[1]+10.0;

        detailsPassSummaryTable.position[0] += 90.0;

        layout.newSpaceTopology(detailsPassSummaryTable, region5);//layout.getSpaceRegion(0));//region3);//			// This is wrong



        Header failHeader = new Header();
        failHeader.headerLevel = Header.HeaderLevel.LVL_3;
        failHeader.letters = "Fail";
        failHeader.position[1] = detailsPassSummaryTable.position[1]- 8.0;
        failHeader.position[0] +=30.0;
        layout.newSpaceTopology(failHeader, region5);//layout.getSpaceRegion(0));//region3);//			// This is wrong


        SummaryTable detailsFailSummaryTable = new SummaryTable();
        detailsFailSummaryTable.table.newRow("Metric       ", "Expected", "Actual");
        detailsFailSummaryTable.table.newRow("Contributions", "171.18","2018.11");
        detailsFailSummaryTable.table.newRow("Beginning Balance", "171.18","2018.11");
        detailsFailSummaryTable.table.newRow("Ending Balance", "171.18","2018.11");

        detailsFailSummaryTable.position[1] += failHeader.position[1] + 10.0;

        detailsFailSummaryTable.position[0] += 90.0;
        detailsFailSummaryTable.excludeHeader = true;
        layout.newSpaceTopology(detailsFailSummaryTable, region5);//layout.getSpaceRegion(0));//region3);//			// This is wrong






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
