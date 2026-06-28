#include <iostream>
using namespace std;

int main() {
    int hour, minute, second;

    cout << "Nhap gio: ";
    cin >> hour;
    cout << "Nhap phut: ";
    cin >> minute;
    cout << "Nhap giay: ";
    cin >> second;

    if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
        cout << "Thoi gian hop le";
    else
        cout << "Thoi gian khong hop le";

    return 0;
}
