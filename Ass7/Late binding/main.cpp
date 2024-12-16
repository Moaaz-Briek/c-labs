#include <iostream>

using namespace std;

class Parent {
private:
    int x = 0;

public:
    Parent () {}
    Parent (int x) {this->x = x;}

    virtual void print() {cout << "Hello from Parent" << endl;}
};

class Child : public Parent {
private:
    int y = 0;

public:
    Child() {}
    Child(int x, int y) : Parent(x) {this->y = y;}

    void print() {cout << "Hello from Child" << endl;}
};

class GrandChild : public Child {
private:
    int z = 0;

public:
    GrandChild() {}
    GrandChild(int x, int y, int z) : Child(x, y) {this->z = z;}

    void print() {cout << "Hello from GrandChild" << endl;}
};

int main()
{
    Parent* ptr1;
    Parent* ptr2;

    Child* ptr3;
    Child* ptr4;

    Parent pr;
    Child ch;
    GrandChild grch;

    ptr1 = &ch;
    ptr1->print();

    ptr2 = &grch;
    ptr2->print();

    ptr3 = &grch;
    ptr3->print();

    ptr4 = &pr;

    return 0;
}
