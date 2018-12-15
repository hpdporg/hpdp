package hpdp;

import java.util.List;
import java.util.ArrayList;

import hpdp.Topology;


public class Layout{

	private List<Topology> space;


	public Layout(){
			space = new ArrayList<>();
			Region region = new Region();
			space.add(region);
			region.setSpace(space);

	}


	public Region getSpaceRegion(int index){
		return (Region)space.get(index);
	}

	public void newSpaceTopology(Topology topology, Region region){

		int spaceRegionIndex = 0;
		int regionNesting = 0;
		int comparisonRegionNesting = 0;
		if (region != null) {

			for (Topology spaceRegion : space) {
				if (spaceRegion.equals(region)) {
					regionNesting = region.nesting;
					++spaceRegionIndex;
					break;
				}
				++spaceRegionIndex;
			}
			int comparisonSpaceRegionIndex = 0;
			comparisonSpaceRegionIndex = spaceRegionIndex;
			comparisonRegionNesting = regionNesting + 1;
			while ((comparisonRegionNesting >regionNesting) &&(comparisonSpaceRegionIndex<space.size() )){

					Topology comparisonSpaceTopology = space.get(comparisonSpaceRegionIndex);
					comparisonRegionNesting = comparisonSpaceTopology.nesting;
					if (comparisonRegionNesting == (regionNesting+1)){

						spaceRegionIndex= comparisonSpaceRegionIndex+1;
					}
					++comparisonSpaceRegionIndex;
			}
			topology.nesting = regionNesting + 1;
		}
		else{
			spaceRegionIndex = space.size();
		}
		space.add(spaceRegionIndex, topology);
		System.out.println("Index: " + spaceRegionIndex + " Region: " + topology.region + " Nesting: " + topology.nesting);
		topology.setSpace(space);


	}

	public List<Topology> getSpace(){
		return space;
	}



}