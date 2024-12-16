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
};

void viewContent(Stack S) {
    cout << "Viewing stack content: ";
    while (!S.IsEmpty()) {
        cout << S.Pop() << " ";
    }

    cout << endl;
}

int main() {
    cout << "----- Copy Constructor Case (1): Pass by value -----\n";
    {
        Stack S1;
        S1.Push(10);
        S1.Push(20);
        S1.Push(30);
        S1.Push(40);

        viewContent(S1);

        cout << "Num = " << S1.Pop() << endl;
        cout << "Num = " << S1.Pop() << endl;
    }

    cout << "\n----- Copy Constructor Case (2): Return by value -----\n";
    {
        Stack S3;
        S3.Push(10);
        S3.Push(20);
        S3.Push(30);
        S3.Push(40);

        Stack S4 = S3.Reverse();

        cout << "Reversed stack pop: " << S4.Pop() << endl;

        cout << "stack pop: " << S3.Pop() << endl;
    }

    cout << "\n----- Copy Constructor Case (3): Explicit creation -----\n";
    {
        Stack S1;
        S1.Push(10);
        S1.Push(20);
        S1.Push(30);
        S1.Push(40);

        Stack S3(S1);

        for (int i = 0; i < 4; i++) S3.Pop();

        for (int i = 0; i < 4; i++) S3.Push(-1);

        cout << "Num = " << S1.Pop() << endl;
        cout << "Num = " << S1.Pop() << endl;
    }

    return 0;
}
