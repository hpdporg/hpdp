package hpdp;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.FileSystemNotFoundException;
import java.util.List;
import java.util.ArrayList;

import hpdp.shapes.Chart.Trace;
import hpdp.storage.*;
import hpdp.HTML;

public class Trans{


	private List<HTML> htmls;
	private Storage storage;
	public enum ExposureLocation{
		HTML_FILE,HTML_MEMORY
	}
	ExposureLocation exposureLocation;
	public boolean realTime = false;



	public Trans(){

		storage = null;
		htmls = new ArrayList<>();
	}


	public HTML newHTML(){
		HTML html = new HTML();
		htmls.add(html);

		return html;
	}

	public void exposureLocation(ExposureLocation exposureLocation){

		this.exposureLocation = exposureLocation;
		if (this.exposureLocation.equals(ExposureLocation.HTML_FILE)){
			storage = new Storage();
		}
		else if(this.exposureLocation.equals(ExposureLocation.HTML_MEMORY)){

		}

	}


	public boolean expose(){
		boolean exposed = false;





		if (htmls != null) {
			for (HTML html : htmls) {
				html.expose();
				if (storage != null){
					try{
						storage.writeHTML(html.exposedHTML);
					}catch(IOException e){
						e.printStackTrace();
						exposed = false;
						return false;
					}

				}
			}
		}


		exposed = true;
		return exposed;
	}


	public boolean filePath(String filePath){

			if (storage != null) {
				try {
					storage.newFile(filePath);
				} catch (IOException e) {
					e.printStackTrace();
					return false;
				}

			}

		return true;
	}


	// Sorts Double values
	public Trace sortTraceCoords(Trace trace, int index ){
		List<Double[]> sortedCoords = new ArrayList<>();

		int unsortedSize = trace.coords.size();
		Double[] minimumCoord = null;
		boolean exists = false;
		if (trace.coords != null &&trace.coords.size()!= 0) {

			int passCount = 0;

			while ((unsortedSize >0)) {

				for (Double[] coord : trace.coords) {
					exists = false;
					for (Double[] sortedCoord : sortedCoords) {
						if (coord[index].compareTo(sortedCoord[index])==0) {

							exists = true;

						}
					}

					if (exists == false) {
						if ((minimumCoord == null)) {
							minimumCoord = coord;

							passCount = 0;
						} else if (coord[index].compareTo(minimumCoord[index]) < 0) {
							minimumCoord = coord;
							passCount = 0;
						}
					}
					else if (sortedCoords.size()>0) {
						if ((minimumCoord == null)) {
							if ((passCount > 4) && (coord[index].compareTo(sortedCoords.get(sortedCoords.size() - 1)[index]) == 0)) {    // Duplicate
								minimumCoord = coord;

								exists = false;

							}
						}
						if ((passCount > 4)){				// Duplicate, next pass, need exists as false.
							exists = false;
						}
					}


					if ((exists == false) && (passCount >6 )) {
						sortedCoords.add(minimumCoord);

						--unsortedSize;
						passCount = 0;
						minimumCoord = null;

					}



				}
				++passCount;			// Do not get stuck in a loop with faulty data.








			}

			trace.coords = sortedCoords;
		}

		return trace;
	}

}