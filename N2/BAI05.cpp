#include <iostream>
using namespace std;

void soLonNhat (double a, double b, double c);

int main() {
    double a, b, c;
    
    cout << "Nhap vao 3 so a, b, c: ";
    cin >> a >> b >> c;

    soLonNhat (a, b, c);
    
    return 0;
}

void soLonNhat (double a, double b, double c) {
    double max = a;
    
    if (b > max) {
        max = b;
    }
    
    if (c > max) {
        max = c;
    }

    cout << "So lon nhat la: " << max << endl;
}
