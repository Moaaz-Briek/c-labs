#include <iostream>

using namespace std;


class Complex
{
    private:
        int real = 0;
        int img = 0;

    public:
        Complex() {
            cout << "Default constructor called.\n";
        }

        Complex(int real, int img) {
            this->real = real;
            this->img = img;
            cout << "Parameterized constructor called.\n";
        }

        Complex(int real) {
            this->real = real;
            cout << "Real Parameterized constructor called.\n";
        }

        Complex(const Complex& com) {
            this->real = com.getReal();
            this->img = com.getImg();
            cout << "Copy constructor called.\n";
        }

        ~Complex() {
            cout << "Destructor called.\n";
        }

        void setReal(int real) {
            this->real = real;
        }

        int getReal() const {
            return this->real;
        }

        void setImg(int img) {
            this->img = img;
        }

        int getImg() const {
            return this->img;
        }

        Complex addWithCpy(const Complex);

        Complex addWithoutCpy(const Complex&);
};

Complex Complex::addWithCpy(const Complex c) {
    Complex newC;

    newC.setReal(this->getReal() + c.getReal());
    newC.setImg(this->getImg() + c.getImg());

    return newC;
}

Complex Complex::addWithoutCpy(const Complex& c) {
    Complex newC;

    newC.setReal(this->getReal() + c.getReal());
    newC.setImg(this->getImg() + c.getImg());

    return newC;
}

int main()
{
    cout << "----- Copy Constructor Case (1) ---------\n";
    {
        Complex C1(3, 4), C2(5), C3;
        C3 = C1.addWithCpy(C2);
    }

    cout << "\n----- Pass by ref Case (2) ---------\n";
    {
        Complex C1(3, 4), C2(5), C3;
        C3 = C1.addWithoutCpy(C2);
    }
    return 0;
}
