#include <iostream>

using namespace std;

class Stack
{
private:
    int* Stk;
    int ssize;
    int tos;

public:
    Stack(int ssize) {
        this->ssize = ssize;
        tos = 0;
        Stk = new int[ssize];
		cout << "param constructor called" << endl;
    }

    bool isEmpty() {
        return this->tos == 0;
    }

    bool isFull() {
        return this->tos == this->ssize;
    }

    void push(int num) {
        if (isFull()) {
            cout << "Stack is full." << endl;
            return;
        } else {
            Stk[this->tos++] = num;
        }
    }

    int peak() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            return Stk[this->tos - 1];
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            return Stk[--this->tos];
        }
    }

    void print() {
        for (int i = 0; i < this->tos; i++) {
            cout << "stack element " << i << " is: " << Stk[i] << " - ";
        }

        cout << endl;
    }

    Stack Reverse() {
        Stack newStack(this->ssize);

        for (int i = this->tos - 1; i >= 0 ; i--) {
            newStack.push(Stk[i]);
        }

        return newStack;
    }

	~Stack() {
		for (int i = 0; i < ssize ; i++) {
            Stk[i] = -1;
        }
		cout << "destructor called" << endl;
	}
};

int main()
{
    Stack S1(5);

	S1.push(10);
	S1.push(20);
	S1.push(30);

	cout << S1.peak() << endl; //30
	cout << S1.peak() << endl; //30

	cout << S1.pop() << endl; //30
	cout << S1.pop() << endl; //20
	cout << S1.pop() << endl; //10
	cout << S1.pop() << endl;

	Stack S2(5);

	S2.push(3);
	S2.push(4);
	S2.push(5);
	S2.push(6);

    S2.print();

    S2.Reverse().print();

    cout << S2.Reverse().pop();

    S2.Reverse().print();
    return 0;
}
