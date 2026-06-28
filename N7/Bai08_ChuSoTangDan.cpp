#include <iostream>
using namespace std;

int main() {
    int n, a, b, c, temp;

    cout << "Nhap so nguyen co 3 chu so: ";
    cin >> n;

    if (n < 100 || n > 999) {
        cout << "So nhap vao khong phai la so co 3 chu so";
    } else {
        a = n / 100;
        b = (n / 10) % 10;
        c = n % 10;

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        if (a > c) {
            temp = a;
            a = c;
            c = temp;
        }
        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }

        cout << "Cac chu so tang dan: " << a << b << c;
    }

    return 0;
}
