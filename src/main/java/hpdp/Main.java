package hpdp;

import java.util.List;
import java.util.ArrayList;

import hpdp.*;
import hpdp.forms.*;


/**
 *  Executes HPDP.
*/


public class Main {


	public static void main(String[] args){

		HPDP hpdp = new HPDP();
		Trans trans = hpdp.getTrans();

		HTML html = trans.newHTML();
		html.exposedHTML = "<html style=\"margin:0; padding:0; overflow:hidden\"><body style=\"margin:0; padding:0; overflow:hidden\"><svg version=\"1.1\" baseProfile=\"full\"  style=\"position:fixed; top:0; left:0; height:100%; width:100%\" width=\"100%\" height=\"100%\"  preserveAspectRatio=\"xMidYMid meet\" xmlns=\"http://www.w3.org/2000/svg\">";//viewBox="0 0 100 100"
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
		layout.newSpaceTopology(region2, layout.getSpaceRegion(0));
		region.



		Header header3 = new Header();
		header3.headerLevel = Header.HeaderLevel.LVL_2;
		header3.letters = "Input Data Variations";
		layout.newSpaceTopology(header3, layout.getSpaceRegion(0));

		Header header4 = new Header();
		header4.headerLevel = Header.HeaderLevel.LVL_2;
		header4.letters = "Categories";
		layout.newSpaceTopology(header4, layout.getSpaceRegion(0));

		Header header5 = new Header();
		header5.headerLevel = Header.HeaderLevel.LVL_2;
		header5.letters = "Coverage Ratio";
		layout.newSpaceTopology(header5, layout.getSpaceRegion(0));


		trans.expose();
	}




}

