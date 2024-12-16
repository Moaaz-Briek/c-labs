#include <iostream>
#include <cmath>

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

        int abs() const {
            return sqrt(this->real * this->real + this->img * this->img);
        }

        void print();
        Complex add(const Complex);
        Complex operator=(const Complex);
        Complex operator+ (const Complex);
        Complex operator-(const Complex);
        Complex operator-(int);
        Complex operator+= (const Complex);
        Complex operator-=(const Complex);
        Complex operator++();
        Complex operator--();
        Complex operator++(int);
        Complex operator--(int);
        bool operator==(const Complex);
        bool operator!=(const Complex);
        bool operator>(const Complex);
        bool operator>=(const Complex);
        bool operator<(const Complex);
        bool operator<=(const Complex);
        int operator[](char);
        operator int();
};

void Complex::print() {
    if (real == 0 && img == 0) {
        cout << "0" << endl;
        return;
    }

    if (real != 0)
        cout << real;

    if (img != 0) {
        if (real != 0 && img > 0)
            cout << '+';

        if (img == 1)
            cout << "i";
        else if (img == -1)
            cout << "-i";
        else
            cout << img << "i";
    }

    cout << endl;
}

Complex Complex::add(const Complex c) {
    Complex sum;
    sum.real = this->real + c.getReal();
    sum.img = this->img + c.getImg();

    return sum;
}

Complex Complex::operator=(const Complex c) {
    this->real = c.getReal();
    this->img = c.getImg();

    return *this;
}

Complex Complex::operator-(const Complex c) {
    Complex sum;
    sum.real = this->real - c.getReal();
    sum.img = this->img - c.getImg();

    return sum;
}

Complex Complex::operator-(int number) {
    Complex sum;
    sum.real = this->real - number;
    sum.img = this->img;

    return sum;
}

Complex operator-(int number, Complex com) {
    Complex sum;
    sum.setReal(com.getReal() - number);
    sum.setImg(com.getImg());

    return sum;
}

Complex Complex::operator-=(const Complex c) {
    this->real -= c.getReal();
    this->img -= c.getImg();

    return *this;
}

Complex Complex::operator--() {
    this->real--;

    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);

    this->real--;

    return temp;
}

bool Complex::operator==(const Complex com) {
    return this->real == com.real && this->img == com.img;
}

bool Complex::operator!=(const Complex com) {
    return !(this->real == com.real && this->img == com.img);
}

bool Complex::operator>(const Complex com) {
    return this->abs() > com.abs();
}

bool Complex::operator>=(const Complex com) {
    return this->abs() >= com.abs();
}

bool Complex::operator<(const Complex com) {
    return this->abs() < com.abs();
}

bool Complex::operator<=(const Complex com) {
    return this->abs() <= com.abs();
}

int Complex::operator[](char ch) {
    if (ch != 'r' && ch != 'R' && ch != 'I' && ch != 'i')
        return -1;

    if (ch != 'r' || ch != 'R')
        return this->real;
    else
        return this->img;
}

Complex::operator int() {
    return this->real + this->img;
}

//===========================================//
Complex Complex::operator+(const Complex c) {
    Complex sum;
    sum.real = this->real + c.getReal();
    sum.img = this->img + c.getImg();

    return sum;
}

Complex Complex::operator+=(const Complex c) {
    this->real += c.getReal();
    this->img += c.getImg();

    return *this;
}

Complex Complex::operator++() {
    this->real++;

    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);

    this->real++;

    return temp;
}

int main()
{
    Complex C1(1, 2), C2(3, 4), C3;

    C3 = 10 - C1;

    C3.print();

    return 0;
}
