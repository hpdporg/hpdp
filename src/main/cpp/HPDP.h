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
		void* next;
	} ListItem;

	typedef struct List {
		void* firstItem;
		LONGLONG	listSize;
		LONGLONG	itemsCount;
		LONGLONG	index;
		void* indexItem;
		LONGLONG	indexedItemIndex;
	} List;

	typedef struct Layout {
		List space;
	} Layout;

	typedef struct HTML {
		Layout* layout;
	} HTML;

	typedef struct Topology {
		char* text;
		char* svgText;
		int shape;
		LONGLONG offsetI;
		LONGLONG offsetJ;
		LONGLONG width;
		LONGLONG height;
	} Topology;

	#define TOPOLOGYSHAPE_LETTERS 1
	#define TOPOLOGYSHAPE_RECT 2
	#define TOPOLOGYSHAPE_ELLIPSE 3
	#define TOPOLOGYSHAPE_LINE 4
	#define TOPOLOGYSHAPE_CHART 5
	#define TOPOLOGYSHAPE_TABLE 6
	#define TOPOLOGYSHAPE_ARROW 7


	extern "C" {

		// List
		List* newList();
		void newLastItem(List* list, void* item);
		void* getNextItem(List* list);
		void resetIndex(List* list);
		// File
		void* newFile(char* path);			// Returns void* fileHandle
		void* writeFile(void* fileHandle, char* entry, LONGLONG entrySize);
		// Layout
		Layout* newLayout();
		// HTML
		HTML* newHTML();
		// Topology
		Topology* newTopology();
	}

	class HPDP {
	private:
		string* defaultPath;
		void* htmlFileHandle;
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

		virtual ~HPDP();


	};

}










#endif