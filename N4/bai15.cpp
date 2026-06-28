#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    cout << "Nhap n: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n phai la so nguyen duong";
    }
    else
    {
        int x = sqrt(n);

        if (x * x == n)
            cout << n << " la so chinh phuong";
        else
            cout << n << " khong la so chinh phuong";
    }

    return 0;
}