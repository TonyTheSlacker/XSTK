#include <iostream>
using namespace std;

int main() {
    int ngay, thang, nam, namHienTai;
    cout << "Nhap nam hien tai: "; cin >> namHienTai;
    cout << "Nhap ngay thang nam: "; cin >> ngay >> thang >> nam;

    // 1. Kiem tra nam va thang co ban

    if (nam <= 0 || nam > namHienTai || thang < 1 || thang > 12) {
        cout << "Ngay/thang/nam khong hop le!";
        return 0;
    }

    // 2. Xac dinh so ngay toi da trong thang
    int ngayToiDa;
    switch (thang) {
        case 4: case 6: case 9: case 11:
            ngayToiDa = 30;
            break;
        case 2:
            // Dieu kien nam nhuan day du
            if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
                ngayToiDa = 29;
            else
                ngayToiDa = 28;
            break;
        default: // Cac thang 1, 3, 5, 7, 8, 10, 12
            ngayToiDa = 31;
    }

    // 3. Kiem tra ngay nhap vao voi ngay toi da
    if (ngay >= 1 && ngay <= ngayToiDa) {
        cout << "Ngay/thang/nam hop le!";
    } else {
        cout << "Ngay khong hop le!";
    }

    return 0;
}