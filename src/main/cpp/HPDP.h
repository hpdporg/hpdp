#ifndef HPDP_H
#define HPDP_H

#include <Windows.h>
#include <string>
#include <list>
#include <fstream>


using std::ofstream;
using std::string;

namespace hpdp {

	typedef struct ListItem {
		void* item;
		void* previous;
		LONGLONG nesting;
		void* next;
	} ListItem;

	typedef struct ItemMatch {
		void* item;
		LONGLONG index;
		LONGLONG nesting;
	} ItemMatch;

	typedef struct List {
		void* firstItem;
		LONGLONG	listSize;
		LONGLONG	itemsCount;
		LONGLONG	index;
		void* indexItem;
		LONGLONG	indexedItemIndex;
	} List;

	typedef struct Layout {
		List* space;
	} Layout;

	typedef struct HTML {
		List* layouts;
	} HTML;

	typedef struct Topology {
		char* text;
		char* svgText;
		int shape;
		LONGLONG offsetI;
		LONGLONG offsetJ;
		LONGLONG width;
		LONGLONG height;
		List* space;
	} Topology;

	typedef struct ASMHPDP {					// Wrapper around assembly HPDP struc
		List* htmls;
	} ASMHPDP;

	#define TOPOLOGYSHAPE_LETTERS 1
	#define TOPOLOGYSHAPE_RECT 2
	#define TOPOLOGYSHAPE_ELLIPSE 3
	#define TOPOLOGYSHAPE_LINE 4
	#define TOPOLOGYSHAPE_CHART 5
	#define TOPOLOGYSHAPE_TABLE 6
	#define TOPOLOGYSHAPE_ARROW 7
	#define TOPOLOGYSHAPE_LOGO 8
	#define TOPOLOGYSHAPE_REGION 9

	extern "C" {

	
		
		// List
		List* newList();
		void newLastItem(List* list, void* item);
		void* getNextItem(List* list);
		void* getNextItemNesting(List* list);
		void* nextItemNesting(List* list, LONGLONG nesting);
		void resetIndex(List* list);
		void* newNextItem(List* list, void* item);
		void* getPriorItem(List* list);
		void* getNextItemMatch(List* list, void* itemMatch);
		void* getNextItemMatchComp(List* list, void* itemMatch, LONGLONG comp);
		// Letters
		char* numAsLetters(LONGLONG num);
		LONGLONG letterLength(char* letters);
		char* appendLetters(char* letters, char* newLetters);
		// File
		void* newFile(char* path);			// Returns void* fileHandle
		void* writeFile(void* fileHandle, char* entry, LONGLONG entrySize);
		// HPDP
		ASMHPDP* newHPDP();
		void expose(ASMHPDP* asmHPDP);
		// Layout
		Layout* newLayout();
		char* getSVGStartTag();
		char* getSVGEndTag();
		// HTML
		HTML* newHTML();
		void exposeHTML(HTML* html);
		// Topology
		Topology* newTopology();
		char* getTopologyStartTag(Topology* topology);
		char* getTopologyEndTag(Topology* topology);
		void newShape(Topology* topology, int shape);



	}

	class HPDP {
	private:
		string* defaultPath;
		void* htmlFileHandle;
		ASMHPDP* asmHPDP;
	public:

		HPDP();
		void writeHTML(string* path);
		//newSVG
		//newElement
		//elementText
		//elementshape
		//elementOffset
		//elementColor
		//nestElement
		//html->layout->newLast
		//line->intersect
		//line->arrow
		//newRegion
		//nestRegion

		//getTopologyRegion uses same nesting
		//newSpaceTopology space topology region

		//Region flags
		// xoffsetFromPriorRegionBound
			// i,j, or k
		//Bound
			//Displacement
			//FitNestedTopologies
				//Include Padding

		//Topology flags
		// xoffsetFromPriorRegionBound
		// i,j, or k
		// xoffsetFromPriorTopologyBound
		// i, j, or k

		//List
		//getNextItemNesting list
		//nextItemNesting list nesting
		//moveNextItem list index
		//moveNextItems list endIndex index
		//newNextItem
		//getPriorItem
		//getNextItemMatch

		//rep

		
		//expose
			//startTag
			//getRegion
			//
		//offsets into members use generic exposer
		//setOffset
			//takes shape param
		//width, offset per shape

		//get arrays index with shape param

		//opacity addresses array, shape as index
		//textOpacityTag, rectOpacityTag

		//tags relevant based on shape
			// width relevant when rect, line 
			// roundedness relevant
			// stroke

		//CoInduce relevancy
			// shape
		//coInduce tagStart
			// shape
		//coInduce tagEnd
			// shape

		//match shape and width, roundedness
			// get relevancy, start, end tag

		// match with offset
				// get value

		//setID
		//setXOffset
		//setYOffset
		//setFill
		//setFontSize
		//setStrokeColor
		//setText


		//newChart
		//chartITitle
		//chartJTitle
		//newLastChartDataSet
		//dataSet->newLastChartTrace
		//trace-->color(conditiom)
		//trace->newLastPoint(condition)

		//newTable
		//newLastITitle
		//newLastJTitle
		//newLastChartDataSet
		//dataSet->newLastChartTrace
		//trace-->color(conditiom)
		//trace->newLastPoint(condition)

		//dataset
		//newLastDataSetSeries
		//sort
		//re-sort
		//delimiter
		
		//sum
		//value contqins?
		//value more
		// value less
		//

		//Letters
		//numAsLetters
		//appendLetters letters, newLetters
		//lettersLength
		//replaceLetters letters, index, newLetters, patternTokensList
		//getLetters letters patternTokensList

		//Pattern tokens
		//number, count, letter, count, symbol, count,numberorLetter, count, numberLetterorSymbol, count
		//length
		//until
		//startIndex
		//startPattern
		//character or number

		//expose
			//Topology offsets based on references



		//scripting

		virtual ~HPDP();


	};

}










#endif