#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n / 100; //hàng trăm
    int b = (n / 10) % 10; //hàng chục
    int c = n % 10; //hàng đơn vị

    // Sắp xếp 3 chữ số theo thứ tự tăng dần
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    cout << a << b << c;
    return 0;
}
