#ifndef ASM_INCLUDES_H
#define ASM_INCLUDES_H

#include <Windows.h>
#include <string>
#include <list>
#include <fstream>
#include <sstream>





using namespace std;

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
	void* itemMatch;
} List;

typedef struct Layout {
	List* space;
} Layout;

typedef struct HTML {
	List* layouts;
	char* text;
} HTML;

typedef struct Topology {
	char* text;
	char* svgText;
	int shape;
	LONGLONG offsetI;
	LONGLONG offsetJ;
	LONGLONG width;
	LONGLONG height;
	LONGLONG size;
	char* textAnchor;
	char* fill;
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
	void newSpaceTopology(List* space, Topology* topology, Topology* region);
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
	Topology* getTopologyRegion(Topology* topology);


}



} // namespace hpdp



#endif