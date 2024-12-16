#include <iostream>
#include <graphics.h>

using namespace std;

class Point{
private:
    int x = 0, y = 0;

public:
    Point () {}
    Point (int a, int b) { this->setX(a); this->setY(b); }

    int getX() {return this->x;}
    void setX(int x) {this->x = x;}

    int getY() {return this->y;}
    void setY(int y) {this->y = y;}
};

class Line{
private:
    Point Start;
    Point End;

public:
    Line () {}
    Line (int a, int b, int c, int d) : Start(a, b), End(c, d) {}
    Line (Point P1, Point P2) : Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY()) {}

    void Draw() {
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rectang {
private:
    Point UC;
    Point LC;

public:
    Rectang () : UC(), LC() {}
    Rectang (int a, int b, int c, int d) : UC(a, b), LC(c, d) {}
    Rectang (Point P1, Point P2) : UC(P1.getX(), P1.getY()), LC(P2.getX(), P2.getY()) {}

    void Draw() {
        rectangle(UC.getX(), UC.getY(), LC.getX(), LC.getY());
    }
};

class Circle{
private:
    Point Center;
    int red = 1;

public:
    Circle () : Center(100, 100) {}
    Circle (int a, int b, int red) : Center(a, b) {this->red = red;}
    Circle (Point P1, int red) : Center(P1.getX(), P1.getY()) {this->red = red;}

    void setRed(int red) {this->red = red;}
    int getRed() {return this->red;}

    void Draw() {
        circle(Center.getX(), Center.getY(), this->red);
    }
};

int main()
{
    Point p1(100, 200);
    Point p2(500, 600);

    Line L(p1, p2);

    Rectang R(p1, p2);

    Circle C(p1, 100);

    initwindow(900, 900);

    L.Draw();
    R.Draw();
    C.Draw();

    getch();
    closegraph();

    return 0;
}
