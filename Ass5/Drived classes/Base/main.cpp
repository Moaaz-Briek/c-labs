#include <iostream>

using namespace std;

class Parent {
private:
    int x = 0 ;

protected:
    int y = 0;

public:
    Parent () {cout << "Parent parameterless constructor is called";};
    Parent (int x, int y) {this->x = x; this->y = y; cout << "Parent parameterized constructor is called";};

    void setX(int x) {this->x = x;};
    int getX() {return this->x;};

    void setY(int y) {this->y = y;};
    int setY(int y) {this->y = y;};

    int sum() {return this->x + this->y};

    ~Parent() {cout << "Parent destructor is called";};
};

class Child : public Parent {
private:
    int z = 0;

public:
    Child () {cout << "Child parameterless constructor is called";};
    Child (int x, int y, int z) : Parent (x, y) {this->z = z; cout << "Child parameterized constructor is called";};

    void setZ(int z) {this->z = z;};
    int getZ() {return this->z;};

    int sum () {return this->z + Parent::sum()};

    ~ Child () {cout << "Child destructor is called";}
};

class GrandChild : public Child {
private:
    int m = 0;

public:
    GrandChild () {cout << "GrandChild parameterless constructor is called";};
    GrandChild (int x, int y, int z, int m) : Child (x, y, z) {this->m = m; cout << "GrandChild parameterized constructor is called";};

    void setM(int m) {this->m = m;};
    int getM() {return this->m;};

    int sum () {return this->m + Child::sum()};

    ~ GrandChild () {cout << "GrandChild destructor is called";}
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
