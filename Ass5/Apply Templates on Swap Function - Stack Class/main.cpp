#include <iostream>
#include <math.h>

using namespace std;

void br() {
    cout<<"\n =============================================== \n";
}

template <typename T>
void Swap(T &N1, T &N2) {
    T temp;
    temp = N1;
    N1 = N2;
    N2 = temp;
}

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

template <class T>
class Stack {
private:
    T* Stk;
    int Tos = 0;
    int Size = 5;

public:
    Stack(){
        Stk = new T[Size];
        cout << "Default constructor called.\n";
    }

    Stack(int Size){
        this->Size = Size;
        Stk = new T[Size];
        cout << "Parameterized constructor called.\n";
    }

    ~Stack() {
        delete[] Stk;
        cout << "Destructor called.\n";
    }

    Stack(const Stack& other){
        this->Size = other.Size;
        this->Tos = other.Tos;
        Stk = new T[Size];
        for (int i = 0; i <= Tos; i++) {
            Stk[i] = other.Stk[i];
        }
        cout << "Copy constructor called.\n";
    }

    bool IsFull() const {
        return Tos == Size;
    }

    bool IsEmpty() const {
        return Tos == 0;
    }

    void push(T value) {
        if (IsFull()) {
            cout << "Stack is full. Cannot push\n";
            return;
        }
        Stk[Tos++] = value;
    }

    T pop() {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        return Stk[--Tos];
    }

    void viewContent(Stack S) {
        cout << "Viewing stack content: ";
        while (!S.IsEmpty()) {
            cout << S.pop() << " ";
        }
        cout << endl;
    }

    Stack Reverse() {
        Stack reversed(Size);
        for (int i = Tos - 1; i >= 0; i--) {
            reversed.push(Stk[i]);
        }
        return reversed;
    }
};

int main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    br();

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    br();

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.print();

    cout<<"\nComplex2 After Swap: "<<endl;
    C2.print();

    br();

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop();

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop();

    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    C.print();

    return 0;
}
