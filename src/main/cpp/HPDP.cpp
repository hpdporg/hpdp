#include "HPDP.h"

using namespace hpdp;
using namespace std;


HPDP::HPDP(){
	this->defaultPath = new string("HTML.html");
	this->htmlFileHandle = NULL;
	this->asmHPDP = newHPDP();

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
	
	entrySize = (LONGLONG)(strlen(getSVGStartTag()));
	writeFile(this->htmlFileHandle, getSVGStartTag(), entrySize);
	Topology* topology = newTopology();
	newShape(topology, TOPOLOGYSHAPE_LETTERS);
	entrySize = (LONGLONG)(strlen(getTopologyStartTag(topology)));
	writeFile(this->htmlFileHandle, getTopologyStartTag(topology), entrySize);
	char* textEntry = "x=\"10\" y=\"10\">";// width = \"30\" height=\"30\"";
	char* textEntry2 = "Statements Test Automation";
	char* textEntry3 = appendLetters(textEntry, textEntry2);


	entrySize = (LONGLONG)(strlen(textEntry3));
	writeFile(this->htmlFileHandle, textEntry3, entrySize);
	entrySize = (LONGLONG)(strlen(getTopologyEndTag(topology)));
	writeFile(this->htmlFileHandle, getTopologyEndTag(topology), entrySize);
	entrySize = (LONGLONG)(strlen(getSVGEndTag()));
	writeFile(this->htmlFileHandle, getSVGEndTag(), entrySize);
	HTML* html = newHTML();
	newLastItem(this->asmHPDP->htmls, html);
	expose(this->asmHPDP);

}

void HPDP::exposeCHTMLs(){
	for (list<CHTML*>::iterator listIterator = cHTMLList->begin(); 
		listIterator != cHTMLList->end(); ++listIterator) {
			(*listIterator)->expose();
	}
}

HPDP::~HPDP(){

    
}