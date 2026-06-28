#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    cout << "Tang dan: " << a << " " << b << " " << c << "\n";
    return 0;
}