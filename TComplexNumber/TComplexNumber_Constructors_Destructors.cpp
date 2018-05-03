#include "TComplexNumber.h"
#include "TComplexNumber_Exception.h"
#include<inttypes.h>
#include<cmath>
#include <string>

using namespace std;


string validChars = "°()e^.-+ij1234567890";

bool validateString(const string* aString){

    bool valideString = false;

    size_t len_aString = aString->size();
    size_t len_validChars = validChars.size();

    for(size_t i = 0; i < len_aString; ++i){

            valideString = false;

        for(size_t j = 0; j < len_validChars; ++j){

            if(aString->at(i) == validChars.at(j)){
                valideString = true;
                break;
            }

        }
        if(!valideString) return false;
    }
    return true;
}

bool convertFromString(double *const aAbs, double *const aPhase, double *const aReal, double *const aImg, const string* aString){
    return false; ///TODO
}


inline double getPhase_if_aReal_is_0(const double aImg){

    if(aImg == 0){
        return  0;
    }
    else if(aImg < 0){
        return 3*pi/2;
    }
    else{
        return pi/2;
    }

}

TComplexNumber::TComplexNumber(const double aReal, const double aImg):fReal(aReal),fImg(aImg),fAbs(sqrt(pow(aReal,2)*pow(aImg,2))),fPhase((aReal == 0)?(0):(atan(aImg/aReal))) {

    if(aReal == 0){
        SetPhase_unsave(getPhase_if_aReal_is_0(aImg));
    }

}
TComplexNumber::TComplexNumber(const TComplexNumber &aCN):fReal(aCN.GetReal()),fImg(aCN.GetImg()),fAbs(aCN.GetAbs()),fPhase(aCN.GetPhase_rad()) {}

TComplexNumber::TComplexNumber(const string* aString){

    if(false == validateString(aString)) throw TComplexNumber_Exception("String for initializing constructor invalid");

    convertFromString(&fAbs,&fPhase,&fReal,&fImg, aString);

}
TComplexNumber::TComplexNumber():fReal(0),fImg(0),fAbs(0),fPhase(0) {}
TComplexNumber::~TComplexNumber() {}
