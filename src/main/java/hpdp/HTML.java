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
				//int ind = 0;
				for (Topology topology : layout.getSpace()) {
					exposedHTML += topology.expose();
					//////System.out.println("Ind, size, nesting " + ind + " " + topology.size[1] + " " + topology.nesting);
				//			++ind;
				}
				int ind = 0;
				for (Topology topology : layout.getSpace()) {
					//exposedHTML += topology.expose();
					////System.out.println("Ind, size, nesting, position " + ind + " " + topology.size[1] + " " + topology.nesting+" " + topology.position[1]);
					++ind;
				}

			}
			exposedHTML += "</svg></div></body></html>";
		}
		exposed = true;
	}

	public Layout getLayout(int index){
		return layouts.get(index);
	}

}