#ifndef CTRANS_H
#define CTRANS_H

#include "HPDP.h"


namespace hpdp {

class CTrans{
private:
	HTML* exposedHTML;
	enum ExposureLocation{HTML_FILE,HTML_MEMORY};
	ExposureLocation exposeLocation;

public:

CTrans();

 void expose();
 void exposureLocation(ExposureLocation exposureLocation);		// Location of view. Can be HTML stored as file as opposed to in memory and accessed by network requests.
 void exposureInterval();										// Once, or in a loop.
 
virtual ~CTrans();


};

} //namespace hpdp











#endif