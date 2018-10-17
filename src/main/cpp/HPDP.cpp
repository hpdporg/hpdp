#include "HPDP.h"

using namespace hpdp;



HPDP::HPDP(){
	this->defaultPath = new string("HTML.html");
	this->htmlFileHandle = NULL;

}

void HPDP::writeHTML(string* path) {
	
	if (path == NULL) {
		this->htmlFileHandle = newFile((char*)defaultPath->c_str());
	}
	else {
		this->htmlFileHandle  = newFile((char*)path->c_str());
	}
	
	char* entry = "ABCD";
	LONGLONG entrySize = (LONGLONG)(strlen(entry));//(LONGLONG*)malloc(sizeof(LONGLONG));
	//*entrySize = (LONGLONG)(strlen(entry));
	char** entryPtr = (char**)malloc(sizeof(char**));
	*entryPtr = entry;
	writeFile(this->htmlFileHandle,entry, entrySize);


}

HPDP::~HPDP(){

    
}