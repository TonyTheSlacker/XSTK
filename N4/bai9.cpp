#include <iostream>
using namespace std;

int main() {
    int d, m, y;
    cin >> d;
    cin.ignore();
    cin >> m;
    cin.ignore();
    cin >> y;
    
    int maxd = 0;
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxd=31; break;
        case 4: case 6: case 9: case 11: maxd=30; break;
        case 2: maxd = ((y%4==0 && y%100!=0) || y%400==0) ? 29 : 28;
    }
    
    if(m>0 && m<13 && y>0 && d>0 && d<=maxd)
        cout << d << "/" << m << "/" << y << " la ngay hop le.";
    else
        cout << d << "/" << m << "/" << y << " la ngay khong hop le.";
}