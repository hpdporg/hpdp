#ifndef HPDP_H
#define HPDP_H

#include <Windows.h>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

#include "AsmIncludes.h"
#include "CHTML.h"


using namespace std;

namespace hpdp {

class HPDP {
private:
	string* defaultPath;
	void* htmlFileHandle;
	ASMHPDP* asmHPDP;
	list<CHTML*>* cHTMLList;
public:

	HPDP();
	void writeHTML(string* path);
	void exposeCHTMLs();
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