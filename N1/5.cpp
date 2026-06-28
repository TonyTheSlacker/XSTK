#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    int max_val = a;
    if (b > max_val) max_val = b;
    if (c > max_val) max_val = c;
    cout << "So lon nhat la: " << max_val << "\n";
    return 0;
}