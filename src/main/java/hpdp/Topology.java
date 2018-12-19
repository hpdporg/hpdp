package hpdp;

import java.util.List;
import java.util.ArrayList;


public class Topology{

	public String exposedText;					// TO-DO change to private
	TopologyShape topologyShape;
	int nesting = 0;
	public String letters;
	public boolean region = false;
	public boolean snap = false;


	private List<Topology> space;					// TO-DO change to protected with getters, setters
	protected List<Topology> topologies = null;

	public enum TopologyShape{
		LETTERS
	}

	public double[] position;			// TO-DO change to protected with getters, setters
	public double[] size;

	public Topology(){
		exposedText = "";
		topologyShape = null;
		position = new double[2];
		size = new double[2];
		region = false;
	}


	public String expose(){
		Region region = getTopologyRegion(this);
	//	region = getTopologyRegion(region);
		Region priorRegion = getPriorRegion(this);
	//	Region higherRegion = getHigherRegion(this);


		double[] priorRegionPosition;
		double[] priorRegionSize;
		double[] regionSize = region.getSize();
		double[] higherRegionPosition;
		double[] higherRegionSize;

		if ((priorRegion != this) && (priorRegion != region) && (priorRegion != null)) {
			priorRegionPosition = priorRegion.getPosition();
			priorRegionSize = priorRegion.getSize();
			//position[0] = priorRegionPosition[0] + priorRegionSize[0];
			position[1] = priorRegionPosition[1] + priorRegionSize[1];

			//regionSize[0] = regionSize[0] + size[0];
		/*	regionSize[1] = regionSize[1] + size[1];
			priorRegionSize[1] = priorRegionSize[1] + regionSize[1];// + size[1];
			priorRegionSize[0] = priorRegionSize[0];// + size[1];

			priorRegion.setSize(priorRegionSize);*/
		}
		else {
			priorRegion = null;
		}



	/*	////System.out.println((priorRegion != this));
		////System.out.println((priorRegion != region));
		////System.out.println((priorRegion != null));
		//System.out.println((region != null));
		//System.out.println((region != this));*/

/*		if ((higherRegion != this) && (higherRegion != region) && (higherRegion != null)){
			higherRegionPosition = higherRegion.getPosition();
			higherRegionSize = higherRegion.getSize();
			//position[0] = priorRegionPosition[0] + priorRegionSize[0];
			//System.out.println("ABC2222222222222");
			//regionSize[0] = regionSize[0] + size[0];
			higherRegionSize[1] =  higherRegionSize[1]+ size[1];
			higherRegion.setSize(higherRegionSize);
			higherRegionPosition[1] =  higherRegionPosition[1]+ position[1];
			higherRegion.setPosition(higherRegionPosition);

		}
*/
		double[] regionPosition = region.getPosition();

		//position[0] = regionPosition[0] + regionSize[0];
		if (priorRegion ==null) {
			position[1] += regionPosition[1] + regionSize[1];
		}
		else{
			position[1] = regionPosition[1] + regionSize[1];
		}

		if (nesting !=0) {
			regionSize[0] = regionSize[0] + size[0];
			regionSize[1] = regionSize[1] + size[1];
		}
		region.setSize(regionSize);

		Region higherRegion = region;
		while (region != (higherRegion = region.getTopologyRegion(region))){
			//regionPosition = higherRegion.getPosition();

			regionSize = higherRegion.getSize();
			regionSize[0] = regionSize[0] + size[0];
			regionSize[1] = regionSize[1] + size[1];

			higherRegion.setSize(regionSize);

			region = higherRegion;
		}


		////System.out.println("Position: " +position[0] + position[1]);
		////System.out.println("Size: " +size[0] + size[1]);

		return exposedText;
	}


	public Region getTopologyRegion(Topology topology){
		Region region = null;


		int spaceRegionIndex = 0;

		for (Topology spaceRegion : space) {
			if (spaceRegion.equals(topology)) {
				--spaceRegionIndex;
				break;
			}
			++spaceRegionIndex;
		}
		////System.out.println("Base: " + spaceRegionIndex);
		if (spaceRegionIndex<0){
			spaceRegionIndex = 0;
		}
		int spaceRegionNesting = topology.nesting;
		while (!(spaceRegionNesting == (topology.nesting -1))){
			Topology spaceTopology = space.get(spaceRegionIndex);
			--spaceRegionIndex;
			if (spaceTopology.region){
				region = (Region)spaceTopology;
			}
			else{
				continue;
			}

			spaceRegionNesting = region.nesting;

			if (spaceRegionIndex<0){
				if (!(spaceRegionNesting == (topology.nesting -1))){
					if (topology.region) {
						region = (Region) topology;
					}
				}
				break;
			}

		}

		return region;
	}
	public Region getPriorRegion(Topology topology){
		Region region = null;


		int spaceRegionIndex = 0;

		for (Topology spaceRegion : space) {
			if (spaceRegion.equals(topology)) {
				--spaceRegionIndex;
				break;
			}
			++spaceRegionIndex;
		}
		if (spaceRegionIndex<0){
			spaceRegionIndex = 0;
		}
		int spaceRegionNesting = topology.nesting -1;
		while (spaceRegionIndex>=0){
			Topology spaceTopology = space.get(spaceRegionIndex);
			if (spaceTopology.region){
				region = (Region)spaceTopology;
			}

			if ((region != null) && (region.region)) {
				spaceRegionNesting = region.nesting;
				if ((spaceRegionNesting <= (topology.nesting))) {

																						// Ensure prior Region is not before higher region

					break;
				}
				//else{
				//	region = null;
				//}
			}

			--spaceRegionIndex;
		}


		return region;
	}

	public Region getHigherRegion(Topology topology){
		Region region = null;


		int spaceRegionIndex = 0;

		for (Topology spaceRegion : space) {
			if (spaceRegion.equals(topology)) {
				--spaceRegionIndex;
				break;
			}
			++spaceRegionIndex;
		}
		if (spaceRegionIndex<0){
			spaceRegionIndex = 0;
		}
		int spaceRegionNesting = topology.nesting -1;
		while (spaceRegionIndex>=0){
			region = (Region)space.get(spaceRegionIndex);
			if (region.region) {
				spaceRegionNesting = region.nesting;
				if ((spaceRegionNesting < (topology.nesting))) {
					break;
				}
			}
			--spaceRegionIndex;
		}


		return region;
	}


	public double[] getPosition(){
		return this.position;
	}

	public double[] getSize(){
		return this.size;
	}

	public void setPosition(double[] position){
		this.position = position;
	}

	public void setSize(double[] size){
		this.size = size;
	}

	public void setSpace(List<Topology> space){
		this.space = space;
	}


}