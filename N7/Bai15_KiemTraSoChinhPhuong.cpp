#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, can;

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong";
    } else {
        can = sqrt(n);
        if (can * can == n)
            cout << n << " la so chinh phuong";
        else
            cout << n << " khong phai la so chinh phuong";
    }

    return 0;
}
