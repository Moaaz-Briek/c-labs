#include <iostream>
#include <graphics.h>

using namespace std;

class Shape {
protected:
    int color = 15;
public:
    Shape () {}
    Shape (int color) {this->setColor(color);}

    void setColor(int color) {this->color = color;}
    int getColor() {return this->color;}

    virtual void Draw() = 0;
};

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

class Line : public Shape{
private:
    Point Start;
    Point End;

public:
    Line () {}
    Line (int a, int b, int c, int d, int color) : Shape(color), Start(a, b), End(c, d) {}
    Line (Point P1, Point P2, int color) : Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY()), Shape(color){}

    void Draw() {
        setcolor(this->getColor());
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rectang : public Shape {
private:
    Point UC;
    Point LC;

public:
    Rectang () : UC(), LC() {}
    Rectang (int a, int b, int c, int d, int color) : UC(a, b), LC(c, d), Shape(color) {}
    Rectang (Point P1, Point P2, int color) : UC(P1.getX(), P1.getY()), LC(P2.getX(), P2.getY()), Shape(color) {}

    void Draw() {
        setcolor(this->getColor());
        rectangle(UC.getX(), UC.getY(), LC.getX(), LC.getY());
    }
};

class Circle : public Shape{
private:
    Point Center;
    int red = 1;

public:
    Circle () {}
    Circle (int a, int b, int red, int color) : Center(a, b), Shape(color) {this->red = red;}
    Circle (Point P1, int red, int color) : Center(P1.getX(), P1.getY()), Shape(color) {this->red = red;}

    void setRed(int red) {this->red = red;}
    int getRed() {return this->red;}

    void Draw() {
        setcolor(this->getColor());
        circle(Center.getX(), Center.getY(), this->red);
    }
};

class Picture {
private:
    Shape** shapeArr = NULL;
    int shapeNums = 0;

public:
    Picture() {}
    Picture(Shape** shapeArr, int shapeNums) {this->setShapes(shapeArr, shapeNums);}

    void setShapes(Shape** shapes, int shapeNums) {this->shapeArr = shapes; this->shapeNums = shapeNums;}

    void paint() { for(int i = 0; i < this->shapeNums; i++) this->shapeArr[i]->Draw(); }
};

int main()
{
    Point UC1(50, 50);
    Point LC1(600, 600);

    Point UC2(120, 120);
    Point LC2(520, 520);

    Point UC3(180, 180);
    Point LC3(450, 450);


    Rectang r1(UC1, LC1, RED); Rectang r2(UC2, LC2, BLUE); Rectang r3(UC3, LC3, YELLOW);

    Circle c1(UC1, 10, RED); Circle c2(UC1, 20, BLUE); Circle c3(UC1, 30, RED);
    Circle c4(LC1, 10, WHITE); Circle c5(LC1, 20, CYAN); Circle c6(LC1, 30, RED);
    Circle c7(UC2, 10, BLUE); Circle c8(UC2, 20, YELLOW);
    Circle c9(LC2, 10, GREEN); Circle c10(LC2, 20, RED);
    Circle c11(UC3, 10, WHITE);
    Circle c12(LC3, 10, RED);

    Line l(UC1, LC1, WHITE);

    Shape* shapes[] = {
        &r1, &r2, &r3,
        &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10, &c11, &c12,
        &l
    };

    Picture picture;
    picture.setShapes(shapes, 16);

    initwindow(1200, 1200);

    picture.paint();

    getch();
    closegraph();

    return 0;
}
