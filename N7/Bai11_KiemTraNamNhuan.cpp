#include <iostream>
using namespace std;

int main() {
    int day, month, year;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        cout << year << " la nam nhuan";
    else
        cout << year << " khong phai la nam nhuan";

    return 0;
}
