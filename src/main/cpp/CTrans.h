#ifndef CTRANS_H
#define CTRANS_H

#include "AsmIncludes.h"
#include "CHTML.h"

namespace hpdp {

class CTrans{
private:
	HTML* exposedHTML;
	enum ExposureLocation{HTML_FILE,HTML_MEMORY};
	ExposureLocation exposeLocation;
	list<CHTML*>* cHTMLList;
	string* defaultPath;
	void* htmlFileHandle;
	string* path;

public:

CTrans();

 void expose();
 void exposureLocation(ExposureLocation exposureLocation);		// Location of view. Can be HTML stored as file as opposed to in memory and accessed by network requests.
 void exposureInterval();										// Once, or in a loop.
 void exposeCHTMLs();											// Translate values into visualization formatting.
 void changeHTMLFilePath(string* path);

virtual ~CTrans();


};

} //namespace hpdp











#endif