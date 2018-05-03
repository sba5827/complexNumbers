#ifndef TCOMPLEXNUMBER_H
#define TCOMPLEXNUMBER_H

#include<string>

using namespace std;

const double pi = 3.14159265359;


class TComplexNumber
{
    public:

        TComplexNumber();
        TComplexNumber(const TComplexNumber &aCN);
        TComplexNumber(const string* aStream);
        TComplexNumber(const double aReal, const double aImg);

        virtual ~TComplexNumber();

        //getter
        double GetReal()const { return fReal; }
        double GetImg()const { return fImg; }
        double GetAbs()const { return fAbs; }
        double GetPhase_rad()const { return fPhase; }
        double GetPhase_grad()const { return fPhase*360/(2*pi); }

        //setter
        void SetReal(const double aVal);
        void SetImg(const double aVal);
        void SetAbs(const double aVal);
        void SetPhase_rad(const double aVal);
        void SetPhase_grad(const double aVal);


        //Operators
        TComplexNumber operator+(const TComplexNumber&);
        TComplexNumber operator-(const TComplexNumber&);
        TComplexNumber operator*(const TComplexNumber&);
        TComplexNumber operator/(const TComplexNumber&);

        bool operator+=(const TComplexNumber&);
        bool operator-=(const TComplexNumber&);
        bool operator*=(const TComplexNumber&);
        bool operator/=(const TComplexNumber&);
        bool operator=(const TComplexNumber&);
        bool operator==(const TComplexNumber&);
        bool operator!=(const TComplexNumber&);
        bool operator<(const TComplexNumber&);
        bool operator>(const TComplexNumber&);
        bool operator<=(const TComplexNumber&);
        bool operator>=(const TComplexNumber&);

        //other

        void printCartesian(void);
        void printPolar(void);

    protected:

        void recalculateXY_components(void);
        void recalculatePolar_components(void);

        void SetReal_unsave(const double aVal) { fReal = aVal; }
        void SetImg_unsave(const double aVal) { fImg = aVal; }
        void SetAbs_unsave(const double aVal) { fAbs = aVal; }
        void SetPhase_unsave(const double aVal) { fPhase = aVal; }

    private:

        double fReal;
        double fImg;
        double fAbs;
        double fPhase;
};

#endif // TCOMPLEXNUMBER_H
