#include "CTrans.h"

using namespace hpdp;


CTrans::CTrans(){
	this->exposeLocation = ExposureLocation::HTML_MEMORY;
	this->defaultPath = new string("HTML.html");
	this->htmlFileHandle = NULL;
}


 void CTrans::expose(){
	if (this->exposeLocation == ExposureLocation::HTML_FILE){
	
			
			exposeCHTMLs();
			
			char* htmlText = NULL;

			for (list<CHTML*>::iterator listIterator = cHTMLList->begin(); 
					listIterator != cHTMLList->end(); ++listIterator) {
							if (path == NULL) {
								this->htmlFileHandle = newFile((char*)defaultPath->c_str());
							}
							else {
									this->htmlFileHandle  = newFile((char*)path->c_str());
							}
						htmlText = getSVGStartTag();
						htmlText = appendLetters(htmlText, (*listIterator)->getText());
						htmlText = appendLetters(htmlText, getSVGEndTag());
						LONGLONG entrySize = (LONGLONG)letterLength(htmlText);
						writeFile(this->htmlFileHandle, htmlText, entrySize);
			}
	
	 }
	 else if(this->exposeLocation == ExposureLocation::HTML_MEMORY){
		 //TO-DO: HTML_MEMORY implementation
	 }
 }
 void CTrans::exposureLocation(ExposureLocation exposureLocation){
	 this->exposeLocation = exposureLocation;
 }
 void CTrans::exposureInterval(){

 }

 void CTrans::exposeCHTMLs(){
	for (list<CHTML*>::iterator listIterator = cHTMLList->begin(); 
		listIterator != cHTMLList->end(); ++listIterator) {
			(*listIterator)->expose();
	}
}


void CTrans::changeHTMLFilePath(string* path){
	this->path = path;
}

CTrans::~CTrans(){

    
}