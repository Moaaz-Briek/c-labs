#include <iostream>

using namespace std;

class Queue
{
private:
    int* Q;
    int head = 0, tail = 0, ssize;

public:
    Queue() {
        setSize(5);
        Q = new int[5];
    }

    Queue(int ssize) {
        setSize(ssize);
        Q = new int[ssize];
    }

    void setSize(int ssize) {
        this->ssize = ssize;
    }

    int getSize() {
        return this->ssize;
    }

    bool isEmpty() {
        return this->tail == 0;
    }

    bool isFull() {
        return this->tail == this->ssize;
    }

    void enQueue(int num) {
        if (!isFull())
            Q[this->tail++] = num;
        else {
            cout << "Queue is full" << endl;
        }
    }

    int deQueue() {
        if (!isEmpty()) {
            int num = Q[this->head];

            for (int i = 0; i < this->tail; i++) {
                Q[i] = Q[i+1];
            }
            --this->tail;

            return num;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    q.enQueue(20);
    q.enQueue(30);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    return 0;
}
