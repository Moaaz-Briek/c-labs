#include <iostream>
using namespace std;

class Stack {
private:
    int* Stk;
    int Tos = 0;
    int Size = 5;

public:
    Stack(){
        Stk = new int[Size];
        cout << "Default constructor called.\n";
    }

    Stack(int Size){
        this->Size = Size;
        Stk = new int[Size];
        cout << "Parameterized constructor called.\n";
    }

    ~Stack() {
        delete[] Stk;
        cout << "Destructor called.\n";
    }

    Stack(const Stack& other){
        this->Size = other.Size;
        this->Tos = other.Tos;
        Stk = new int[Size];
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

    void Push(int value) {
        if (IsFull()) {
            cout << "Stack is full. Cannot push " << value << ".\n";
            return;
        }
        Stk[Tos++] = value;
    }

    int Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        return Stk[--Tos];
    }

    friend void viewContent(Stack S);

    Stack Reverse() {
        Stack reversed(Size);
        for (int i = Tos - 1; i >= 0; i--) {
            reversed.Push(Stk[i]);
        }
        return reversed;
    }

    Stack operator= (const Stack s) {
        this->Size = s.Size;
        this->Tos = s.Tos;

        delete [] this->Stk;

        this->Stk = new int[this->Size];

        for (int i=0; i < this->Size; i++)
            this->Stk[i] = s.Stk[i];

        return s;
    }

    Stack operator+(const Stack& s) const {
        Stack result(this->Size + s.Size);

        for (int i = 0; i < this->Tos; i++) {
            result.Push(this->Stk[i]);
        }

        for (int i = 0; i < s.Tos; i++) {
            result.Push(s.Stk[i]);
        }

        return result;
    }
};

void viewContent(Stack S) {
    cout << "Viewing stack content: ";
    while (!S.IsEmpty()) {
        cout << S.Pop() << " ";
    }
    cout << endl;
}

int main() {
    Stack S1(10), S2, S3;

    S1.Push(1);
    S1.Push(2);
    S1.Push(3);

    S2 = S1;

    S2.Push(4);
    S2.Push(5);

    S3 = S1 + S2;

    viewContent(S1);
    viewContent(S2);
    viewContent(S3);

    return 0;
}
