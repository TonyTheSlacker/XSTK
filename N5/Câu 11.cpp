#include <iostream>
using namespace std;
struct Year{
    int year;
    int month;
    int day;
}; 

bool checkLeap(Year y) {
    if (y.year % 4 == 0 && y.year % 100 != 0) {
        return true;
    }
    if (y.year % 400 == 0) {
        return true;
    }
    return false;
}

int main(){
    Year y;
    cin >> y.year >> y.month >> y.day;
    cout << (checkLeap(y) ? "Leap Year" : "Not Leap Year") << endl;
    return 0;
}