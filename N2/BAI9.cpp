#include <iostream>
using namespace std;

int main() {
    int ngay, thang, nam;
    char sep1, sep2; // format DD/MM/YYYY

    cout << "Nhap ngay, thang, nam (cach nhau boi dau cach): ";
    cin >> ngay >> sep1 >> thang >> sep2 >> nam;
    
    bool hop_le = true;
    
    if (nam <= 0 || thang < 1 || thang > 12 || ngay < 1 || sep1 != '/' || sep2 != '/') {
        hop_le = false;
    } else {
        int so_ngay_trong_thang = 0;
        
        switch (thang) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                so_ngay_trong_thang = 31;
                break;
            case 4: case 6: case 9: case 11:
                so_ngay_trong_thang = 30;
                break;
            case 2:
                // Kiem tra nam nhuan
                if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0)) {
                    so_ngay_trong_thang = 29;
                } else {
                    so_ngay_trong_thang = 28;
                }
                break;
        }
        
        // Nếu ngày nhập vào lớn hơn số ngày tối đa của tháng đó
        if (ngay > so_ngay_trong_thang) {
            hop_le = false;
        }
    }
    
    if (hop_le) {
        cout << "Ngay " << ngay << "/" << thang << "/" << nam << " HOP LE " << endl;
    } else {
        cout << "Ngay KHONG HOP LE!" << endl;
    }
    
    return 0;
}