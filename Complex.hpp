#include <string>

using namespace std;

class Complex{
    int _real;
    int _imag;

public:
    Complex(int real,int imag):_real(real),_imag(imag){};



    friend string to_string(Complex& complex){
        return to_string(complex._real) + "+" + to_string(complex._imag) +"i";
    }
};
