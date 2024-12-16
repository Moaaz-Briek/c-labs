#include <iostream>

using namespace std;

template <class T>
class Stack {
private:
    T* Stk;
    int Tos = 0;
    int Size = 5;
    static int counter;

public:
    Stack(){
        Stk = new T[Size];
        counter++;
    }

    Stack(int Size){
        this->Size = Size;
        Stk = new T[Size];
        counter++;
    }

    ~Stack() {
        delete[] Stk;
        counter--;
    }

    Stack(const Stack& other){
        this->Size = other.Size;
        this->Tos = other.Tos;
        Stk = new T[Size];
        for (int i = 0; i <= Tos; i++) {
            Stk[i] = other.Stk[i];
        }
        counter++;
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

    static int getCounter() {return counter;}
};

template <class T>
int Stack <T>::counter = 0;

int main()
{
    Stack<int>S;
    S.push(10);
    S.push(20);

    cout << Stack<int>::getCounter() << endl;

    Stack<int>S2;
    S2.push(10);
    S2.push(20);

    cout << Stack<int>::getCounter() << endl;

    return 0;
}
