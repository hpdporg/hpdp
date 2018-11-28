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
		html.exposedHTML = "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">";
		trans.exposureLocation(Trans.ExposureLocation.HTML_FILE);
		trans.filePath("HTML1.html");

		Header header = new Header();
		trans.expose();
	}




}

