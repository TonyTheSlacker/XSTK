#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap 3 canh a, b, c: ";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) cout << "Day la tam giac deu.\n";
        else if (a == b || a == c || b == c) cout << "Day la tam giac can.\n";
        else if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) cout << "Day la tam giac vuong.\n";
        else cout << "Day la tam giac thuong.\n";
    } else {
        cout << "Khong the tao thanh tam giac.\n";
    }
    return 0;
}