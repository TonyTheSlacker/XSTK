#include <iostream>
using namespace std;

void soLonHon (int a, int b);

int main() {
    int a, b;
    
    cout << "Nhap vao 2 so nguyen: ";
    cin >> a >> b;

    soLonHon (a, b);
    
    return 0;
}

void soLonHon (int a, int b) {
    if (a > b) {
        cout << "So co gia tri lon hon la: " << a << endl;
    } 
    else if (a < b) {
        cout << "So co gia tri lon hon la: " << b << endl;
    }
    else {
        cout << "Hai so co gia tri bang nhau = " << a << endl;
    }
}
