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
        setcolor(RED);
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
        setcolor(BLUE);
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
        setcolor(GREEN);
        circle(Center.getX(), Center.getY(), this->red);
    }
};

class Picture {
private:
    int RectNum = 0, CircleNum = 0, LineNum = 0;
    Rectang* pRects = NULL;
    Circle* pCirlces = NULL;
    Line* pLines = NULL;

public:
    Picture() {}
    Picture(Rectang* pRec, Circle* pCir, Line* pLine, int RectNum, int CircleNum, int LineNume) {
        this->setRects(pRec, RectNum);
        this->setCircles(pCir, CircleNum);
        this->setLines(pLine, LineNume);
    }

    void setRects(Rectang* pRects, int rectNum) {this->pRects = pRects; this->RectNum = rectNum;}
    void setCircles(Circle* pCircles, int circleNum) {this->pCirlces = pCircles; this->CircleNum = circleNum;}
    void setLines(Line* pLines, int lineNum) {this->pLines = pLines; this->LineNum = LineNum;}

    void paint() {
        int i;

        for(i = 0; i < this->RectNum; i++)
            this->pRects[i].Draw();

        for(i = 0; i < this->CircleNum; i++)
            this->pCirlces[i].Draw();

        for(i = 0; i <= this->LineNum; i++)
            this->pLines[i].Draw();
    }
};

int main()
{
    Point UC1(50, 50);
    Point LC1(600, 600);

    Point UC2(120, 120);
    Point LC2(520, 520);

    Point UC3(180, 180);
    Point LC3(450, 450);

    Picture picture;

    Rectang recs[3] = {Rectang(UC1, LC1), Rectang(UC2, LC2), Rectang(UC3, LC3)};
    picture.setRects(recs, 3);

    Circle circs[12] = {
        Circle(UC1, 10), Circle(UC1, 20), Circle(UC1, 30),
        Circle(LC1, 10), Circle(LC1, 20), Circle(LC1, 30),
        Circle(UC2, 10), Circle(UC2, 20),
        Circle(LC2, 10), Circle(LC2, 20),
        Circle(UC3, 10),
        Circle(LC3, 10),
    };
    picture.setCircles(circs, 12);

    Line l(UC1, LC1);
    picture.setLines(&l, 1);

    initwindow(900, 900);

    picture.paint();

    getch();
    closegraph();

    return 0;
}
