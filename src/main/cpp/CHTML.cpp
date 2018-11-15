#include "CHTML.h"


using namespace hpdp;

CHTML::CHTML(){
	this->html = newHTML();

}

CHTML* CHTML::expose(){

	List* layouts = this->html->layouts;

	while (layouts->index < layouts->itemsCount){
		Layout* layout = (Layout*) getNextItem(layouts);
		List* space = layout->space;
		while (space->index < space->itemsCount){
			Topology* topology = (Topology*) getNextItem(space);
			int topologyShape = topology->shape;
			if (topologyShape == TOPOLOGYSHAPE_LETTERS){
				char* startTag = getTopologyStartTag(topology);
				char* topologyText = topology->text;
				LONGLONG offsetI = topology->offsetI;
				LONGLONG offsetJ = topology->offsetJ;
				LONGLONG width = topology->width;
				LONGLONG height = topology->height;
				LONGLONG size = topology->size;
				char* textAnchor = topology->textAnchor;
				char* fill = topology->fill;
				char* id = (char*)malloc((sizeof(int)*8+1));
				itoa((int)topology,id,10);
				char* endTag = getTopologyEndTag(topology);


				std::ostringstream stringStream;
				stringStream << startTag << " ";
				stringStream << " dx=\""<<offsetI<<"\" ";
				stringStream << " dy=\""<<offsetJ<<"\" ";
				stringStream << " font-size=\""<<size<<"\" ";
				stringStream << " text-anchor=\""<<textAnchor<<"\" ";
				stringStream << " fill=\""<<fill<<"\"> ";
				stringStream << topologyText;
				stringStream << endTag;
				
			}else if (topologyShape == TOPOLOGYSHAPE_RECT){
			
			
			}else if (topologyShape == TOPOLOGYSHAPE_ELLIPSE){
			
			}else if (topologyShape == TOPOLOGYSHAPE_LINE){
			
			}else if (topologyShape == TOPOLOGYSHAPE_CHART){
			
			}else if (topologyShape == TOPOLOGYSHAPE_TABLE){
			
			}else if (topologyShape == TOPOLOGYSHAPE_ARROW){
			
			}else if (topologyShape == TOPOLOGYSHAPE_LOGO){
			
			}else if (topologyShape == TOPOLOGYSHAPE_REGION){
			
			}


		}

	}

	

	

	return this;
}





CHTML::~CHTML(){

    
}