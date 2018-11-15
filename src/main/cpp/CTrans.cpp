#include "CTrans.h"

using namespace hpdp;


CTrans::CTrans(){
	this->exposeLocation = ExposureLocation::HTML_MEMORY;
}


 void CTrans::expose(){
	 if (this->exposeLocation == ExposureLocation::HTML_FILE){

	 }
 }
 void CTrans::exposureLocation(ExposureLocation exposureLocation){
	 this->exposeLocation = exposureLocation;
 }
 void CTrans::exposureInterval(){

 }




CTrans::~CTrans(){

    
}