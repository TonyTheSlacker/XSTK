#include <iostream>
#include <climits>
using namespace std;

void inChuSoTangDan(int n)
{
    int c = n%10; //don vi
    int b = (n/10)%10; // chuc
    int a =  n/100; //tram

    if (a > b) { int t = a; a = b; b = t; }
    if (a > c) { int t = a; a = c; c = t; }
    if (b > c) { int t = b; b = c; c = t; }

    cout << a << " " << b << " " << c;
}

int main()
{
    int n;
    cout << "Nhap vao so nguyen co 3 chu so: ";
    cin >> n;
    inChuSoTangDan(n);


}