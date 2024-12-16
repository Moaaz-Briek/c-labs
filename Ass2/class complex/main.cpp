#include <iostream>

using namespace std;


class Complex
{
private:
    int real;
    int img;

public:
    Complex() {
        this->real = 0;
        this->img = 0;
        cout << "Zero params cons" << endl;
    }

    Complex(int real, int img) {
        this->real = real;
        this->img = img;
        cout << "Two params cons" << endl;
    }

    Complex(int real) {
        this->real = real;
        this->img = 0;
        cout << "One param cons" << endl;
    }

    void setReal(int real) {
        this->real = real;
    }

    int getReal() {
        return this->real;
    }

    void setImg(int img) {
        this->img = img;
    }

    int getImg() {
        return this->img;
    }

    void print() {
        // Handle zero case first
        if (real == 0 && img == 0) {
            cout << "0" << endl;
            return;
        }

        // Print real part if non-zero
        if (real != 0)
            cout << real;

        // Handle imaginary part
        if (img != 0) {
            if (real != 0 && img > 0)
                cout << '+';

            // Special cases for 1 and -1
            if (img == 1)
                cout << "i";
            else if (img == -1)
                cout << "-i";
            else
                cout << img << "i";
        }

        cout << endl;
    }

    Complex addComplex(Complex c) {
        Complex newC;

        newC.setReal(this->real + c.getReal());
        newC.setImg(this->img + c.getImg());

        return newC;
    }

    void subtractComplex(Complex c) {
        this->real -= c.getReal();
        this->img -= c.getImg();
    }

    ~Complex() {
        cout  << "Des is called" << endl;
    }
};
int main()
{
    Complex C1(3, 4), C2(5), C3;

    C1.print();
    C2.print();
    C3.print();

    C3 = C1.addComplex(C2);

    C3.print();
    return 0;
}
