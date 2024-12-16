#include <iostream>
using namespace std;

class Complex
{
private:
	int real =0 , imag = 0;
public:
	Complex() {}
	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real number ";
	in >> c.real;
	cout << "Enter Imaginary number ";
	in >> c.imag;
	return in;
}

int main()
{
    Complex c1;
    cin >> c1;
    cout << "The complex object is ";
    cout << c1;
    return 0;
}
