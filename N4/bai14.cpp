#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a + b <= c ||
        a + c <= b ||
        b + c <= a)
    {
        cout << "Khong phai tam giac";
    }
    else if (a == b && b == c)
    {
        cout << "Tam giac deu";
    }
    else if ((a == b || a == c || b == c) &&
        (a * a + b * b == c * c ||
            a * a + c * c == b * b ||
            b * b + c * c == a * a))
    {
        cout << "Tam giac vuong can";
    }
    else if (a * a + b * b == c * c ||
        a * a + c * c == b * b ||
        b * b + c * c == a * a)
    {
        cout << "Tam giac vuong";
    }
    else if (a == b || a == c || b == c)
    {
        cout << "Tam giac can";
    }
    else
    {
        cout << "Tam giac thuong";
    }
}