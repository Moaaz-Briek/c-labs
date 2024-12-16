#include <iostream>

using namespace std;

class Shape {
private:
    int dim1 = 0;
    int dim2 = 0;

public:
    Shape () {}
    Shape (int d1, int d2) {this->dim1 = d1; this->dim2 = d2;}

    virtual int calcArea() = 0;

    void setDim1(int dim1) {this->dim1 = dim1;}
    int getDim1() {return this->dim1;}

    void setDim2(int dim2) {this->dim2 = dim2;}
    int getDim2() {return this->dim2;}
};

class Rec : public Shape {
public:
    Rec () {}
    Rec (int d1, int d2) : Shape (d1, d2) {};

    int calcArea() {return this->getDim1() * this->getDim2();}
};

class Square : public Shape {
public:
    Square () {}
    Square (int d1) : Shape (d1, d1) {};

    int calcArea() {return this->getDim1() * this->getDim2();}
    void setDim(int num){this->setDim1(num); this->setDim2(num);}
};

class Circle : public Shape {
public:
    Circle () {}
    Circle (int d1) : Shape(d1, d1) {};

    int calcArea() {return 3.14 * this->getDim1() * this->getDim2();}
    void setDim(int num){this->setDim1(num); this->setDim2(num);}
};

class Triangle : public Shape {
public:
    Triangle () {}
    Triangle (int d1, int d2) : Shape (d1, d2) {};

    int calcArea() {return 0.5 * this->getDim1() * this->getDim2();}
};

float sumOfAreas(Shape** Arr, int Size) {
    float sum = 0;
    for (int i = 0; i < Size; i ++) {
        sum += Arr[i]->calcArea();
    }
    return sum;

}

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

    Shape* Arr[] = {&r1, &s1, &c1, &t1};

    cout << "Sum Of Areas: " << sumOfAreas(Arr, 4) << endl;
    return 0;
}
