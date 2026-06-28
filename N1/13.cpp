#include <iostream>
using namespace std;

int main() {
    double km, total = 0;
    cout << "Nhap so km: ";
    cin >> km;

    if (km <= 1) {
        total = 5000;
    } else if (km <= 30) {
        total = 5000 + ((km - 1) / 0.2) * 1000;
    } else {
        total = 5000 + (29 / 0.2) * 1000 + (km - 30) * 3000;
    }
    cout << "Tong tien can tra: " << total << " VND\n";
    return 0;
}