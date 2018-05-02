#include "stringToNumber.h"
#include <math.h>

int getNumber(const char c){
    switch(c){
    case'0':
        return 0;
    case'1':
        return 1;
    case'2':
        return 2;
    case'3':
        return 3;
    case'4':
        return 4;
    case'5':
        return 5;
    case'6':
        return 6;
    case'7':
        return 7;
    case'8':
        return 8;
    case'9':
        return 9;
    default:
        return -1;
    }
}

double convertToNumber(const string* aStream){

    bool isSigned = false;

    int stringSize = aStream->size();
    int dotPosition = aStream->find(".");

    double returnValue = 0;

    int i = 0;

    if(aStream->at(0) == '-'){
        isSigned = true;
        ++i;
    }

    if(dotPosition == std::string::npos){

        for(i; i < stringSize; ++i){

        int number = getNumber(aStream->at(i));

        if(number == -1){
           return -1;
        }

        returnValue += (double)number * (double)pow(10,stringSize-i-1);

        }

    }
    else{

        for(i; i < dotPosition; ++i){

        int number = getNumber(aStream->at(i));

        if(number == -1){
           return -1;
        }

        returnValue += (double)number * (double)pow(10,dotPosition-i-1);

        }

        ++i;

        for(i; i < stringSize; ++i){

            int number = getNumber(aStream->at(i));

            if(number == -1){
               return -1;
            }

            returnValue += (double)number * (double)pow(10,dotPosition-i);

        }

    }

    if(isSigned){
        returnValue *= -1;
    }

    return returnValue;

}
