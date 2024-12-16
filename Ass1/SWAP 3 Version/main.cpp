#include <iostream>

using namespace std;

void swapByValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = x;
}

void swapByAddress(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapByRef(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x, y;
    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "Values before swap by value are: " << x << " -- " << y << endl;
    swapByValue(x, y);
    cout << "Values after swap by value are: " << x << " -- " << y << endl;

    cout << "=============================================================\n";

    cout << "Values before swap by address are: " << x << " -- " << y << endl;
    swapByAddress(&x, &y);
    cout << "Values after swap by address are: " << x << " -- " << y << endl;

    cout << "=============================================================\n";

    cout << "Values before swap by ref are: " << x << " -- " << y << endl;
    swapByRef(x, y);
    cout << "Values after swap by ref are: " << x << " -- " << y << endl;
    return 0;
}
