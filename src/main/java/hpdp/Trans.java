package hpdp;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.FileSystemNotFoundException;
import java.util.List;
import java.util.ArrayList;
import hpdp.storage.*;

public class Trans{


	private List<HTML> htmls;
	private Storage storage;
	public enum ExposureLocation{
		HTML_FILE,HTML_MEMORY
	}
	ExposureLocation exposureLocation;


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
		if (storage != null){
			try {
				storage.newFile(filePath);
			}catch(IOException e){
				e.printStackTrace();
				return false;
			}

		}
		return true;
	}


}