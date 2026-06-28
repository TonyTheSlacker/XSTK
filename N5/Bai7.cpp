#include <iostream>
using namespace std;

void timViTriLonNhat(int n) {
    // Tách 3 chữ số tương tự bài 8
    int tram = n / 100;       
    int chuc = (n / 10) % 10; 
    int donVi = n % 10;       

    // Tìm giá trị lớn nhất (Max)
    int maxVal = tram;
    if (chuc > maxVal) maxVal = chuc;
    if (donVi > maxVal) maxVal = donVi;

    // Xuất vị trí chứa giá trị lớn nhất theo yêu cầu bài 7
    cout << "Chu so lon nhat la " << maxVal << " nam o: ";
    
    if (tram == maxVal) cout << "hang tram ";
    if (chuc == maxVal) cout << "hang chuc ";
    if (donVi == maxVal) cout << "hang don vi ";
}

int main() {
    int n;
    cout << "Nhap vao so nguyen co 3 chu so: ";
    cin >> n;
    
    if (n < 100 || n > 999) {
        cout << "Vui long nhap so co 3 chu so!";
    } else {
        timViTriLonNhat(n);
    }
    return 0;
}