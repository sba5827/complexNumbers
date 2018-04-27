#ifndef TCOMPLEXNUMBER_EXCEPTION_H
#define TCOMPLEXNUMBER_EXCEPTION_H

#include<exception>

class TComplexNumber_Exception: public std::exception
{
    public:
        TComplexNumber_Exception( const char* aString);
        virtual ~TComplexNumber_Exception();

        virtual const char* what() const throw(){return fexceptionString;}


    protected:

    private:
        const char* fexceptionString;
};

#endif // TCOMPLEXNUMBER_EXCEPTION_H
