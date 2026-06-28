#include <iostream>
using namespace std;

int main() {
    double km;
    int tien;

    cout << "Nhap tong quang duong di duoc (km): ";
    cin >> km;

    if (km <= 0) {
        cout << "Quang duong khong hop le";
    } else if (km <= 1) {
        tien = 5000;
        cout << "So tien phai tra: " << tien << " dong";
    } else if (km <= 30) {
        int soMet = (int)((km - 1) * 1000 + 0.5);
        int soLan200m = soMet / 200;
        if (soMet % 200 != 0)
            soLan200m++;
        tien = 5000 + soLan200m * 1000;
        cout << "So tien phai tra: " << tien << " dong";
    } else {
        int soMet = 29 * 1000;
        int soLan200m = soMet / 200;
        int tien30km = 5000 + soLan200m * 1000;
        int kmThem = (int)(km - 30);
        if (km - 30 > kmThem)
            kmThem++;
        tien = tien30km + kmThem * 3000;
        cout << "So tien phai tra: " << tien << " dong";
    }

    return 0;
}
