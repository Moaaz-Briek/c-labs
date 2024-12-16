#include <iostream>

using namespace std;

void br() {
    cout << "========================================\n";
}

struct ComplexNum {
private:
    int real;
    int img;

public:
    void setReal(int rel) {
        real = rel;
    }

    int getReal() {
        return real;
    }

    void setImg(int im) {
        img = im;
    }

    int getImg() {
        return img;
    }

    void print() {
        // Handle zero case first
        if (real == 0 && img == 0) {
            cout << "0" << endl;
            return;
        }

        // Print real part if non-zero
        if (real != 0)
            cout << real;

        // Handle imaginary part
        if (img != 0) {
            if (real != 0 && img > 0)
                cout << '+';

            // Special cases for 1 and -1
            if (img == 1)
                cout << "i";
            else if (img == -1)
                cout << "-i";
            else
                cout << img << "i";
        }

        cout << endl;
    }

    void addComplex(ComplexNum c) {
        real += c.getReal();
        img += c.getImg();
    }

    void subtractComplex(ComplexNum c) {
        real -= c.getReal();
        img -= c.getImg();
    }
};

ComplexNum addComplex(ComplexNum c1, ComplexNum c2) {
    ComplexNum c3;

    c3.setReal(c1.getReal() + c2.getReal());
    c3.setImg(c1.getImg() + c2.getImg());

    return c3;
}

ComplexNum subtractComplex(ComplexNum c1, ComplexNum c2) {
    ComplexNum c3;

    c3.setReal(c1.getReal() - c2.getReal());
    c3.setImg(c1.getImg() - c2.getImg());

    return c3;
}

void print(ComplexNum c) {
    c.print();
}

int main()
{
    int real, img;
    ComplexNum* c;
    ComplexNum c1;
    ComplexNum c2;

    cout << "Enter first complex real number: " ;
    cin >> real;
    c1.setReal(real);

    cout << "Enter first complex imaginary number: " ;
    cin >> img;
    c1.setImg(img);
    c1.print();

    br();

    cout << "Enter second complex real number: " ;
    cin >> real;
    c2.setReal(real);

    cout << "Enter second complex imaginary number: " ;
    cin >> img;
    c2.setImg(img);
    c2.print();

    br();

    c2.addComplex(c1);
    c2.print();

    return 0;
}
