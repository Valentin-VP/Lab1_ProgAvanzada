
#include "DtMonopatin.h"

DtMonopatin::DtMonopatin(){}
DtMonopatin::DtMonopatin(bool b){
    this->tieneLuces=b;
}
DtMonopatin::~DtMonopatin(){}

bool DtMonopatin::getTieneLuces(){
    if(tieneLuces){
        return true;
    }else{
        return false;
    }
}

void DtMonopatin::setTieneLuces(bool b){
    this->tieneLuces=b;
}
