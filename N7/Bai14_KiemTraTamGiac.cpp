#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Nhap 3 so nguyen duong a, b, c: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Ba so phai la so nguyen duong";
    } else if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Ba so khong tao thanh tam giac";
    } else {
        cout << "Ba so tao thanh tam giac" << endl;

        if (a == b && b == c)
            cout << "Tam giac deu";
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            if (a == b || a == c || b == c)
                cout << "Tam giac vuong can";
            else
                cout << "Tam giac vuong";
        } else if (a == b || a == c || b == c)
            cout << "Tam giac can";
        else
            cout << "Tam giac thuong";
    }

    return 0;
}
