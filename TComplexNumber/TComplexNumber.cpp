#include "TComplexNumber.h"
#include "TComplexNumber_Exeption.h"
#include<cmath>
#include <iostream>

using namespace std;


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

TComplexNumber::TComplexNumber(const TComplexNumber &aCN):fReal(aCN.GetReal()),fImg(aCN.GetImg()),fAbs(aCN.GetAbs()),fPhase(aCN.GetPhase_rad()){

}
TComplexNumber::TComplexNumber(const char* aStream){}

TComplexNumber::TComplexNumber():fReal(0),fImg(0),fAbs(0),fPhase(0) {}

TComplexNumber::~TComplexNumber() {}

TComplexNumber TComplexNumber::operator+(const TComplexNumber& x) {

    TComplexNumber cnReturn;

    cnReturn.SetReal(this->GetReal() + x.GetReal());
    cnReturn.SetImg(this->GetImg() + x.GetImg());

    return cnReturn;

}

TComplexNumber TComplexNumber::operator-(const TComplexNumber& x) {

    TComplexNumber cnReturn;

    cnReturn.SetReal(this->GetReal() - x.GetReal());
    cnReturn.SetImg(this->GetImg() - x.GetImg());

    return cnReturn;

}
TComplexNumber TComplexNumber::operator*(const TComplexNumber& x) {

    TComplexNumber cnReturn;

    cnReturn.SetAbs(this->GetAbs() * x.GetAbs());
    cnReturn.SetPhase_rad(this->GetPhase_rad() + x.GetPhase_rad());

    return cnReturn;

}
TComplexNumber TComplexNumber::operator/(const TComplexNumber& x) {

    if(x.GetAbs() == 0){
        throw TComplexNumber_Exeption("division by zero");
    }

    TComplexNumber cnReturn;

    cnReturn.SetAbs(this->GetAbs() / x.GetAbs());

    cnReturn.SetPhase_rad(this->GetPhase_rad() - x.GetPhase_rad());

    return cnReturn;

}


bool TComplexNumber::operator+=(const TComplexNumber& x) {

    this->SetReal(this->GetReal() + x.GetReal());
    this->SetImg(this->GetImg() + x.GetImg());
    return true;

}
bool TComplexNumber::operator-=(const TComplexNumber& x) {

    this->SetReal(this->GetReal() - x.GetReal());
    this->SetImg(this->GetImg() - x.GetImg());
    return true;

}
bool TComplexNumber::operator*=(const TComplexNumber& x) {

    this->SetAbs(this->GetAbs() * x.GetAbs());
    this->SetPhase_rad(this->GetPhase_rad() + x.GetPhase_rad());
    return true;

}
bool TComplexNumber::operator/=(const TComplexNumber& x) {

    if(x.GetAbs() == 0){
        throw TComplexNumber_Exeption("division by zero");
    }

    this->SetAbs(this->GetAbs() / x.GetAbs());
    this->SetPhase_rad(this->GetPhase_rad() - x.GetPhase_rad());
    return true;

}
bool TComplexNumber::operator=(const TComplexNumber& x) {

    this->SetImg_unsave(x.GetImg());
    this->SetReal_unsave(x.GetReal());
    this->SetAbs_unsave(x.GetAbs());
    this->SetPhase_unsave(x.GetPhase_rad());

    return true;

}
bool TComplexNumber::operator==(const TComplexNumber& x) {

    if((this->GetReal() == x.GetReal()) && (this->GetImg() == x.GetImg())) {
        return true;
    }
    else if((this->GetAbs() == x.GetAbs()) && (this->GetPhase_rad() == x.GetPhase_rad())) {
        return true;
    }
    else {
        return false;
    }

}
bool TComplexNumber::operator!=(const TComplexNumber& x) {
    return !(*this == x);
}
bool TComplexNumber::operator<(const TComplexNumber& x) {
    return this->GetAbs() < x.GetAbs();
}
bool TComplexNumber::operator>(const TComplexNumber& x) {
    return this->GetAbs() > x.GetAbs();
}
bool TComplexNumber::operator<=(const TComplexNumber& x) {

    if(*this != x){
        return (*this < x);
    }

    return true;

}
bool TComplexNumber::operator>=(const TComplexNumber& x) {

    if(*this != x){
        return (*this > x);
    }

    return true;

}
void TComplexNumber::recalculateXY_components(void) {

    SetReal_unsave(cos(GetPhase_rad())*GetAbs());
    SetImg_unsave(sin(GetPhase_rad())*GetAbs());

}
void TComplexNumber::recalculatePolar_components(void){

    SetAbs_unsave(sqrt(pow(GetReal(),2)+pow(GetImg(),2)));

    double quadrantOffest = 0;

    if(GetReal() < 0){
        if(GetImg() > 0){
            quadrantOffest += pi/2;
        }
        else if(GetImg() < 0){
            quadrantOffest += 2*pi/2;
        }
    }
    else if(GetReal() > 0){
        if(GetImg() > 0){

        }
        else if(GetImg() < 0){
            quadrantOffest += 3*pi/2;
        }
    }
    else if(GetReal() == 0){
        SetPhase_unsave((GetImg() > 0)?(pi/2):(3*pi/2));
        return;
    }
    SetPhase_unsave(quadrantOffest + atan(abs(GetImg())/abs(GetReal())));
}
void TComplexNumber::SetReal(const double aVal) {

    fReal = aVal;
    recalculatePolar_components();

}
void TComplexNumber::SetImg(const double aVal) {

    fImg = aVal;
    recalculatePolar_components();

}
void TComplexNumber::SetAbs(const double aVal) {

    fAbs = aVal;
    recalculateXY_components();

}
void TComplexNumber::SetPhase_rad(const double aVal) {

    fPhase = aVal;
    recalculateXY_components();

}

void TComplexNumber::SetPhase_grad(const double aVal) {

    fPhase = aVal/360*(2*pi);
    recalculateXY_components();

}

void TComplexNumber::printCartesian(void){
    cout << GetReal() << ((GetImg()>= 0)?("+"):("")) << GetImg() << "i" << endl;
}

void TComplexNumber::printPolar(void){
    cout << GetAbs() << "e^(i" << GetPhase_rad() << ")" << endl;
}
