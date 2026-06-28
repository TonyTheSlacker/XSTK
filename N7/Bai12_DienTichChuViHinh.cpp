#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;
    double a, b, c, r, area, perimeter;
    const double pi = 3.14;

    cout << "1. Tam giac" << endl;
    cout << "2. Hinh vuong" << endl;
    cout << "3. Hinh chu nhat" << endl;
    cout << "4. Hinh tron" << endl;
    cout << "Chon hinh: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Nhap 3 canh tam giac: ";
            cin >> a >> b >> c;
            if (a + b > c && a + c > b && b + c > a) {
                perimeter = a + b + c;
                double p = perimeter / 2;
                area = sqrt(p * (p - a) * (p - b) * (p - c));
                cout << "Chu vi = " << perimeter << endl;
                cout << "Dien tich = " << area;
            } else {
                cout << "Ba canh khong tao thanh tam giac";
            }
            break;
        case 2:
            cout << "Nhap canh hinh vuong: ";
            cin >> a;
            perimeter = 4 * a;
            area = a * a;
            cout << "Chu vi = " << perimeter << endl;
            cout << "Dien tich = " << area;
            break;
        case 3:
            cout << "Nhap chieu dai va chieu rong: ";
            cin >> a >> b;
            perimeter = 2 * (a + b);
            area = a * b;
            cout << "Chu vi = " << perimeter << endl;
            cout << "Dien tich = " << area;
            break;
        case 4:
            cout << "Nhap ban kinh: ";
            cin >> r;
            perimeter = 2 * pi * r;
            area = pi * r * r;
            cout << "Chu vi = " << perimeter << endl;
            cout << "Dien tich = " << area;
            break;
        default:
            cout << "Lua chon khong hop le";
    }

    return 0;
}
