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

	static boolean skipTests = false;

	public static void main(String[] args){






				if (skipTests == false) {
					DateTest dateTest = new DateTest();
					dateTest.runTest();


	//	ChartTest chartTest = new ChartTest();
	//			chartTest.runTest();

	//	SummaryReportTest summaryReportTest = new SummaryReportTest();
	//	summaryReportTest.runTest();

     //   PaddingTest paddingTest = new PaddingTest();
       // paddingTest.buildHTMLPage();
				}



	}




}

