#include <iostream>
using namespace std;

int main() {
    int day, month, year, maxDay;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    if (year <= 0 || month < 1 || month > 12 || day < 1) {
        cout << "Ngay khong hop le";
    } else {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            maxDay = 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            maxDay = 30;
        else {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                maxDay = 29;
            else
                maxDay = 28;
        }

        if (day <= maxDay)
            cout << "Ngay hop le";
        else
            cout << "Ngay khong hop le";
    }

    return 0;
}
