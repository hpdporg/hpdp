package hpdp;

import java.util.List;
import java.util.ArrayList;

import hpdp.Layout;


public class HTML{

	private boolean exposed;

	private List<Layout> layouts;
	public String exposedHTML;					// TO-DO change to private

	public HTML(){

		exposed = false;
		exposedHTML = null;
		layouts = new ArrayList<>();
		Layout layout = new Layout();
		layouts.add(layout);

	}


	public void expose(){

		if (exposed == false) {
			for (Layout layout : layouts) {
				for (Topology topology : layout.getSpace()) {
					exposedHTML += topology.expose();
				}
			}
			exposedHTML += "</svg></body></html>";
		}
		exposed = true;
	}

	public Layout getLayout(int index){
		return layouts.get(index);
	}

}