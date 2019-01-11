package hpdp;

import hpdp.forms.CompositeTable;
import hpdp.forms.Header;
import hpdp.forms.Scatter;
import hpdp.forms.SummaryTable;
import hpdp.shapes.Chart.Trace;

import java.io.IOException;
import java.util.List;

public class SummaryReportTest {


    public void runTest(){




        HPDP hpdp = new HPDP();
        Trans trans = hpdp.getTrans();
        Scraper scraper = hpdp.getScraper();
        scraper.filePath("DataStore3.csv");
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
        trans.filePath("HTML2.html");

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


        Region summaryTable1Region = new Region();
        //region3.size[1]+= 40.0;
        //region3.size[0] += 40.0;
        summaryTable1Region.position[1] -= 30.0;


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
        header3.letters = "Sub-header 2";
        header3.position[1] -=30.0;
        layout.newSpaceTopology(header3, region4);//layout.getSpaceRegion(0));//region3);//			// This is wrong



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
