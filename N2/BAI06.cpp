#include <iostream>
using namespace std;

void xepTangDan (double a, double b, double c);

int main() {
    double a, b, c;
    
    cout << "Nhap vao 3 so a, b, c: ";
    cin >> a >> b >> c;

    xepTangDan (a, b, c);
    
    return 0;
}

void xepTangDan (double a, double b, double c) {
    double temp;
    
    //So sanh a va b, gan gia tri nho hon cho a
    if (a > b) { 
        temp = a;
        a = b;
        b = temp;
    }
    
    //So sanh b va c, gan gia tri nho hon cho b
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    //Kiem tra lai gia tri giua a va b, gan gia tri nho hon cho a
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    cout << "Thu tu tang dan: " << a << ", " << b << ", " << c << endl;
}
