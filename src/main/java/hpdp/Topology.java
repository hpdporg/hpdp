package hpdp;

import java.util.List;
import java.util.ArrayList;


public class Topology{

	public String exposedText;					// TO-DO change to private
	TopologyShape topologyShape;
	int nesting = 0;
	public String letters;
	public boolean region = false;


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
		region = false;
	}


	public String expose(){
		Region region = getTopologyRegion(this);
		Region priorRegion = getPriorRegion(this);

		double[] priorRegionPosition;
		double[] priorRegionSize;
		double[] regionSize = region.getSize();

	/*	System.out.println((priorRegion != this));
		System.out.println((priorRegion != region));
		System.out.println((priorRegion != null));
		System.out.println((region != null));
		System.out.println((region != this));*/
		if ((priorRegion != this) && (priorRegion != region) && (priorRegion != null)){
			priorRegionPosition = priorRegion.getPosition();
			priorRegionSize = priorRegion.getSize();
			//position[0] = priorRegionPosition[0] + priorRegionSize[0];
			position[1] = priorRegionPosition[1] + priorRegionSize[1];

			//regionSize[0] = regionSize[0] + size[0];
			//regionSize[1] = regionSize[1] + size[1];
		}

		double[] regionPosition = region.getPosition();

		//position[0] = regionPosition[0] + regionSize[0];
		position[1] = regionPosition[1] + regionSize[1];


		regionSize[0] = regionSize[0] + size[0];
		regionSize[1] = regionSize[1] + size[1];

		region.setSize(regionSize);

		System.out.println("Position: " +position[0] + position[1]);
		System.out.println("Size: " +size[0] + size[1]);

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
		System.out.println("Base: " + spaceRegionIndex);
		if (spaceRegionIndex<0){
			spaceRegionIndex = 0;
		}
		int spaceRegionNesting = topology.nesting;
		while (!(spaceRegionNesting == (topology.nesting -1))){
			region = (Region)space.get(spaceRegionIndex);
			spaceRegionNesting = region.nesting;
			--spaceRegionIndex;
			if (spaceRegionIndex<0){
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
			region = (Region)space.get(spaceRegionIndex);
			if (region.region) {
				spaceRegionNesting = region.nesting;
				if ((spaceRegionNesting == (topology.nesting))) {
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