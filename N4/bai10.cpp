#include <iostream>
using namespace std;

int main() {
    int h, m, s; char c;
    cin >> h >> c >> m >> c >> s; // Nhập giờ:phút:giây

    // Kiểm tra giờ (0-23), phút (0-59), giây (0-59)
    if (h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59)
        cout << h << ":" << m << ":" << s << " la thoi gian hop le.";
    else
        cout << h << ":" << m << ":" << s << " la thoi gian khong hop le.";

    return 0;
}