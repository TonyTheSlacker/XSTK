#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n (3 chu so): ";
    cin >> n;
    int tram = n / 100, chuc = (n / 10) % 10, dvi = n % 10;
    int max_digit = tram;
    if (chuc > max_digit) max_digit = chuc;
    if (dvi > max_digit) max_digit = dvi;
    
    if (max_digit == tram) cout << "Chữ số lớn nhất ở hàng trăm (" << tram << ")\n";
    else if (max_digit == chuc) cout << "Chữ số lớn nhất ở hàng chục (" << chuc << ")\n";
    else cout << "Chữ số lớn nhất ở hàng đơn vị (" << dvi << ")\n";
    return 0;
}