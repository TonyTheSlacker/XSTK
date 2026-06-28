#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n (3 chu so): ";
    cin >> n;
    int tram = n / 100, chuc = (n / 10) % 10, dvi = n % 10;
    if (tram > chuc) swap(tram, chuc);
    if (tram > dvi) swap(tram, dvi);
    if (chuc > dvi) swap(chuc, dvi);
    cout << "Tang dan: " << tram << chuc << dvi << "\n";
    return 0;
}