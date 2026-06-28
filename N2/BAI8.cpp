#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Nhap vao mot so nguyen co 3 chu so n: ";
    cin >> n;
    
    n = abs(n);
    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;
    
    if (a > b) { int temp = a; a = b; b = temp; }
    if (a > c) { int temp = a; a = c; c = temp; }
    if (b > c) { int temp = b; b = c; c = temp; }
    
    cout << a << b << c << endl;
    
    return 0;
}