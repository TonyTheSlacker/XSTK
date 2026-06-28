#include <iostream>
using namespace std;

int main() {
    int h, m, s;
    char sep1, sep2; 
    
    cout << "Nhap gio theo dinh dang (hour:minute:second): ";
    cin >> h >> sep1 >> m >> sep2 >> s;
    
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        cout << "Hop le!\n";
    } else {
        cout << "Khong hop le!\n";
    }
    
    return 0;
}