#include <iostream>
using namespace std;

int main() {
    int d, m, y; char c;
    cin >> d >> c >> m >> c >> y; // Nhập ngày/tháng/năm

    // Năm nhuận: chia hết 4 và không chia hết 100, hoặc chia hết 400
    if ((y%4==0 && y%100!=0) || y%400==0)
        cout << y << " la nam nhuan.";
    else
        cout << y << " la nam khong nhuan.";

    return 0;
}