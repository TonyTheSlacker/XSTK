//Bài 7: Tìm vị trí của chữ số lớn nhất trong số có 3 chữ số
#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    int n;
    cout << "Nhap vao mot so nguyen co 3 chu so n: ";
    cin >> n;
    
    n = abs(n); 
    
    int tram = n / 100;
    int chuc = (n / 10) % 10;
    int don_vi = n % 10;
    
    // Tìm giá trị lớn nhất
    int max_val = tram;
    if (chuc > max_val) max_val = chuc;
    if (don_vi > max_val) max_val = don_vi;
    
    // In ra vị trí
    cout << "Chu so lon nhat nam o: ";
    if (max_val == tram) cout << "Hang tram (" << tram << ") ";
    if (max_val == chuc) cout << "Hang chuc (" << chuc << ") ";
    if (max_val == don_vi) cout << "Hang don vi (" << don_vi << ") ";
    cout << endl;
    
    return 0;
}