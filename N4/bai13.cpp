#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double quangDuong;
    double tien;

    cin >> quangDuong;

    if (quangDuong <= 1)
    {
        tien = 5000;
    }
    else if (quangDuong <= 30)
    {
        tien = 5000
            + ceil((quangDuong - 1) * 1000 / 200) * 1000;
    }
    else
    {
        double tien30km =
            5000
            + ceil((30 - 1) * 1000 / 200) * 1000;

        tien = tien30km
            + (quangDuong - 30) * 3000;
    }

    cout << "So tien phai tra: " << tien;

	return 0;

}