#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    int choice;
    cout << "Chon hinh:\n";
    cout << "1. Tam giac (Triangle)\n";
    cout << "2. Hinh vuong (Square)\n";
    cout << "3. Hinh chu nhat (Rectangle)\n";
    cout << "4. Hinh tron (Circle)\n";
    cout << "Nhap lua chon cua ban (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double a, b, c;
            cout << "Nhap 3 canh cua tam giac: ";
            cin >> a >> b >> c;
            
            if (a + b > c && a + c > b && b + c > a) {
                double perimeter = a + b + c; 
                double p = perimeter / 2.0; 
                double area = sqrt(p * (p - a) * (p - b) * (p - c)); 
                
                cout << "Chu vi tam giac: " << perimeter << "\n";
                cout << "Dien tich tam giac: " << area << "\n";
            } else {
                cout << "Loi: Ba canh vua nhap khong tao thanh mot tam giac hop le!\n";
            }
            break;
        }
        case 2: {
            double a;
            cout << "Nhap chieu dai canh hinh vuong: ";
            cin >> a;
            
            if (a > 0) {
                cout << "Chu vi hinh vuong: " << 4 * a << "\n";
                cout << "Dien tich hinh vuong: " << a * a << "\n";
            } else {
                cout << "Loi: Canh phai lon hon 0!\n";
            }
            break;
        }
        case 3: {
            double w, l;
            cout << "Nhap chieu rong va chieu dai hinh chu nhat: ";
            cin >> w >> l;
            
            if (w > 0 && l > 0) {
                cout << "Chu vi hinh chu nhat: " << 2 * (w + l) << "\n";
                cout << "Dien tich hinh chu nhat: " << w * l << "\n";
            } else {
                cout << "Loi: Kich thuoc phai lon hon 0!\n";
            }
            break;
        }
        case 4: {
            double r;
            const double PI = 3.141592653589793;
            cout << "Nhap ban kinh hinh tron: ";
            cin >> r;
            
            if (r > 0) {
                cout << "Chu vi hinh tron: " << 2 * PI * r << "\n";
                cout << "Dien tich hinh tron: " << PI * r * r << "\n";
            } else {
                cout << "Loi: Ban kinh phai lon hon 0!\n";
            }
            break;
        }
        default:
            cout << "Lua chon khong hop le! Vui long chay lai chuong trinh va chon tu 1 den 4.\n";
            break;
    }

    return 0;
}