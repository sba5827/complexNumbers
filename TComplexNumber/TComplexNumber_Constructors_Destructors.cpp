#include "TComplexNumber.h"
#include "TComplexNumber_Exception.h"
#include<inttypes.h>
#include<cmath>
#include <string.h>


const char* validChars = "°()e^.-+ij1234567890";

bool validateString(const char* aString){

    bool valideString = false;

    size_t len_aString = strlen(aString);
    size_t len_validChars = strlen(validChars);

    for(size_t i = 0; i < len_aString; ++i){
        for(size_t j = 0; j < len_validChars; ++j){

            valideString = false;

            if(aString[i] == validChars[j]){
                valideString = true;
                break;
            }

        }
        if(!valideString) return false;
    }
    return true;
}

int64_t getNumberOutOfString_dec(const char* aString, const size_t aDigets){

    int64_t number = 0;

    int sign = 1;

    if(aString[0] == '-'){
        sign = -1;
    }

    for(size_t i = 0; i < aDigets; ++i){
        if(i == 0 && aString[0] == '-') {
            sign = -1;
        }
        switch(aString[i]){

        case '0':
            break;
        case '1':
            number += 1*pow(10,aDigets-i);
            break;
        case '2':
            number += 1*pow(10,aDigets-i);
            break;
        case '3':
            number += 1*pow(10,aDigets-i);
            break;
        case '4':
            number += 1*pow(10,aDigets-i);
            break;
        case '5':
            number += 1*pow(10,aDigets-i);
            break;
        case '6':
            number += 1*pow(10,aDigets-i);
            break;
        case '7':
            number += 1*pow(10,aDigets-i);
            break;
        case '8':
            number += 1*pow(10,aDigets-i);
            break;
        case '9':
            number += 1*pow(10,aDigets-i);
            break;
        default:
            throw TComplexNumber_Exception("InternalError in line 79. TComplexNumber_Constructors_Destructors.cpp");
            break;


        }
    }

    return sign*number;
}

bool convertFromString(double *const aAbs, double *const aPhase, double *const aReal, double *const aImg, const char* aString, size_t aLen){

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
TComplexNumber::TComplexNumber(const char* aString){

    if(false == validateString(aString)) throw TComplexNumber_Exception("String for initializing constructor invalid");

    size_t len = strlen(aString);

    convertFromString(&fAbs,&fPhase,&fReal,&fImg, aString, len);

}
TComplexNumber::TComplexNumber():fReal(0),fImg(0),fAbs(0),fPhase(0) {}
TComplexNumber::~TComplexNumber() {}
