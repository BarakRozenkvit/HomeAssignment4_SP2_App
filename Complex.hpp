#include <string>
#include <iostream>

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
    bool operator<(Complex& other){
        return _real < other._real && _imag < other._imag;
    }

    friend string to_string(Complex& complex){
           return to_string(complex._real) + "+" + to_string(complex._imag) +"i";
       }

    friend ostream& operator<<(ostream& out,Complex& comp){
        out << to_string(comp);
        return out;
    }
};
