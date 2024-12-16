#include <iostream>

using namespace std;

class Shape {
private:
    int dim1 = 0;
    int dim2 = 0;

public:
    Shape () {cout << "Shape parameterless constructor\n";}
    Shape (int d1, int d2) {this->dim1 = d1; this->dim2 = d2; cout << "Shape parameterized constructor\n";}

    virtual int calcArea() = 0;

    void setDim1(int dim1) {this->dim1 = dim1;}
    int getDim1() {return this->dim1;}

    void setDim2(int dim2) {this->dim2 = dim2;}
    int getDim2() {return this->dim2;}

    ~Shape () {cout << "Shape destructor\n";}
};

class Rec : public Shape {
public:
    Rec () {cout << "Rec parameterless constructor\n";}
    Rec (int d1, int d2) : Shape (d1, d2) {};

    int calcArea() {return this->getDim1() * this->getDim2();}
};

class Square : protected Shape {
public:
    Square () {cout << "Square parameterless constructor\n";}
    Square (int d1) : Shape (d1, d1) {};

    int calcArea() {return this->getDim1() * this->getDim2();}
    void setDim(int num){this->setDim1(num); this->setDim2(num);}
};

class Circle : public Square {
public:
    Circle () {cout << "Circle parameterless constructor\n";}
    Circle (int d1) : Square(d1) {};

    int calcArea() {return 3.14 * Square::calcArea();}
};

class Triangle : public Shape {
public:
    Triangle () {cout << "Triangle parameterless constructor\n";}
    Triangle (int d1, int d2) : Shape (d1, d2) {};

    int calcArea() {return 0.5 * this->getDim1() * this->getDim2();}
};

int main()
{
    Rec r1(1, 2);
    cout << r1.calcArea() << endl;

    Square s1;
    s1.setDim(2);
    cout << s1.calcArea() << endl;

    Circle c1;
    c1.setDim(2);
    cout << c1.calcArea() << endl;

    Triangle t1(1, 2);
    cout << t1.calcArea() << endl;

    Shape sh;
    return 0;
}
