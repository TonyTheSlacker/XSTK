#include <iostream>
using namespace std;

int main() {
    int n, tram, chuc, donvi;

    cout << "Nhap so nguyen co 3 chu so: ";
    cin >> n;

    if (n < 100 || n > 999) {
        cout << "So nhap vao khong phai la so co 3 chu so";
    } else {
        tram = n / 100;
        chuc = (n / 10) % 10;
        donvi = n % 10;

        if (tram >= chuc && tram >= donvi)
            cout << "Chu so lon nhat nam o hang tram: " << tram;
        else if (chuc >= tram && chuc >= donvi)
            cout << "Chu so lon nhat nam o hang chuc: " << chuc;
        else
            cout << "Chu so lon nhat nam o hang don vi: " << donvi;
    }

    return 0;
}
