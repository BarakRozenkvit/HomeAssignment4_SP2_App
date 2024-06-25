#include <string>
#include <iostream>
#pragma once

using namespace std;

class Complex{
    int _real;
    int _imag;

public:
    Complex(){};
    Complex(int real,int imag):_real(real),_imag(imag){};

    bool operator==(Complex& comp){
        return _imag == comp._imag && _real == comp._real;
    }

    // TODO: what is < between complex numbers
    /*
     *
שבוע טוב, אני לא מבין את השאלה. בהינתן מספרים מרוכבים z=a+bi,
z'=c+di אתה יכול להשוות את השורש של a^2+b^2 עם השורש של c^2+d^2 ולקחת את המקסימלי.
     */
    bool operator<(Complex& other){
        return _real < other._real && _imag < other._imag;
    }

    friend string to_string(const Complex& complex){
           return to_string(complex._real) + "+" + to_string(complex._imag) +"i";
       }

    friend ostream& operator<<(ostream& out,Complex& comp){
        out << to_string(comp);
        return out;
    }
};
