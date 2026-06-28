#include <iostream>
using namespace std;

int main() {
    int d, m, y;
    char sep1, sep2;
    
    cout << "Nhap theo dinh dang (day/month/year): ";
    cin >> d >> sep1 >> m >> sep2 >> y;
    
    if (y < 0){
        cout << "Khong hop le!";
        return 0;
    }
    bool isLeap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    int daysInMonth = 31;
    
    if (m < 1 || m > 12) {
        cout << "Khong hop le!\n";
        return 0;
    }
    
    if (m == 2) daysInMonth = isLeap ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) daysInMonth = 30;

    if (d < 1 || d > daysInMonth){
        cout << "Khong hop le!\n";
        return 0;
    } 
    
    if(isLeap) cout << "La nam nhuan!";
    else cout << "Khong la nam nhuan!";
    return 0;
}