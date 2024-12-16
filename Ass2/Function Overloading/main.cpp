#include <iostream>
#include <cstring> // For strlen and strcat

using namespace std;

void br() {
    cout << "==========================================\n";
}
class Operation
{
public:
	int add(int x, int y) {
        return x + y;
	}

	int add(int x, int y, int z) {
        return x + y + z;
	}

    void add(char c1, char c2, char c3) {
        string sum;
        sum += c1;
        sum += c2;
        sum += c3;
        cout << "Char sum is: " << sum << endl;
    }

    void add(char* str1, char* str2) {
        int size_of_str1 = strlen(str1);
        int size_of_str2 = strlen(str2);

        char result [size_of_str1 + size_of_str2];

        strcpy(result, str1);

        strcat(result, " ");

        strcat(result, str2);

        cout << "String sum is: " << result << endl;
    }
};

int main()
{
    Operation op;

    int x, y, z;
    char c1, c2, c3;
    char st1[1000], st2[1000];

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "Enter third number: ";
    cin >> z;

    cout << "Summation of first two numbers is: " << op.add(x, y) << endl;
    cout << "Summation of three numbers is: " << op.add(x, y, z) << endl;

    br();

    cout << "Enter first char: ";
    cin >> c1;

    cout << "Enter second char: ";
    cin >> c2;

    cout << "Enter third char: ";
    cin >> c3;

    op.add(c1, c2, c3);

    br();

    cout << "Enter first string: ";
    cin >> st1;

    cout << "Enter second string: ";
    cin >> st2;

    op.add(st1, st2);

    br();
    return 0;
}
