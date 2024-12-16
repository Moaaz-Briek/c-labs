#include <iostream>

using namespace std;

class Date {
private:
    int day = 0, month = 0, year = 0;

public:
    Date() {};

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    };

    void printData() {
      cout << this->day << '/' << this->month << '/' << this->year << endl;
    };

    Date operator=(const Date);
    Date operator+(const Date);
    Date operator-(const Date);
    Date operator++();
    Date operator++(int);
    bool operator==(const Date);
    operator int();
    int operator[](char);
};

Date Date::operator=(Date datte) {
    this->day = datte.day;
    this->month = datte.month;
    this->year = datte.year;

    return *this;
}

Date Date::operator+(Date datte) {
    Date sum;

    sum.day = this->day + datte.day;
    sum.month = this->month + datte.month;
    sum.year = this->year + datte.year;

    return sum;
}

Date Date::operator-(Date datte) {
    Date sum;

    sum.day = this->day - datte.day;
    sum.month = this->month - datte.month;
    sum.year = this->year - datte.year;

    return sum;
}

Date Date::operator++() {
    this->day++;
    this->month++;
    this->year++;

    return *this;
}

Date Date::operator++(int num) {
    Date temp;

    this->day++;
    this->month++;
    this->year++;

    return temp;
}

bool Date::operator==(Date datte) {
    return this->day == datte.day &&
    this->month == datte.month &&
    this->year == datte.year;
}

Date::operator int () {
    return this->day +
    this->month +
    this->year;
}

int Date::operator [] (char ch) {
    if (ch != 'd' && ch != 'D' && ch != 'm' && ch != 'M' && ch != 'Y' && ch != 'y')
        return -1;

    if (ch == 'd' || ch == 'D')
        return this->day;
    else if (ch == 'm' || ch == 'M')
        return this->month;
    else
        return this->year;
}



int main()
{
    Date d1(14,06,1997), d2, d3;

    d1.printData();

    d2 = d1;

    d2.printData();

    d3 = d1 + d2;

    d3.printData();

    ++d3;

    d3.printData();

    cout << d1['d'];

    return 0;
}
