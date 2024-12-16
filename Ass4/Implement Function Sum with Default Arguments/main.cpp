#include <iostream>

using namespace std;

int SUM (int x = 0, int y = 0, int z = 0) {
    return x + y + z;
}

int main()
{
    cout << "-------- Case 1: No args --------\n";
    cout << SUM();

    cout << "\n-------- Case 1: One args (1)--------\n";
    cout << SUM(1);

    cout << "\n-------- Case 1: Two args (1, 2)--------\n";
    cout << SUM(1, 2);

    cout << "\n-------- Case 1: Three args (1, 2, 3)--------\n";
    cout << SUM(1, 2, 3);

    return 0;
}
