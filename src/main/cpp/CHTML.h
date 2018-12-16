#ifndef CHTML_H
#define CHTML_H

#include "AsmIncludes.h"



namespace hpdp{

class CHTML{

private:
	

public:
	HTML* html;

CHTML();

	CHTML* expose();
	char* getText();

virtual ~CHTML();


};

} // namespace hpdp










#endif