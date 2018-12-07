package hpdp;

import java.util.List;
import java.util.ArrayList;


public class Topology{

	public String exposedText;					// TO-DO change to private
	TopologyShape topologyShape;
	int nesting = 0;
	public String letters;


	private List<Topology> space;

	public enum TopologyShape{
		LETTERS
	}

	protected double[] position;
	protected double[] size;

	public Topology(){
		exposedText = "";
		topologyShape = null;
		position = new double[2];
		size = new double[2];
	}


	public String expose(){
		Region region = getTopologyRegion(this);
		double[] regionPosition = region.getPosition();
		double[] regionSize = region.getSize();
		position[0] = regionPosition[0] + regionSize[0];
		position[1] = regionPosition[1] + regionSize[1];


		regionSize[0] = regionSize[0] + size[0];
		regionSize[1] = regionSize[1] + size[1];

		region.setSize(regionSize);

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
		if (spaceRegionIndex<0){
			spaceRegionIndex = 0;
		}
		region = (Region)space.get(spaceRegionIndex);

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