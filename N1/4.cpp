#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "So lon hon la: " << (a > b ? a : b) << "\n";
    return 0;
}