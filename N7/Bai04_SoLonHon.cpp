#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a > b)
        cout << "So lon hon la: " << a;
    else if (b > a)
        cout << "So lon hon la: " << b;
    else
        cout << "Hai so bang nhau";

    return 0;
}
