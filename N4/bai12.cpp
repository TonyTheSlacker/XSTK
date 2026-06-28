#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

struct HinhVuong
{
    double canh;

    double dienTich()
    {
        return canh * canh;
    }

    double chuVi()
    {
        return 4 * canh;
    }
};

struct HinhChuNhat
{
    double dai;
    double rong;

    double dienTich()
    {
        return dai * rong;
    }

    double chuVi()
    {
        return 2 * (dai + rong);
    }
};

struct HinhTron
{
    double banKinh;

    double dienTich()
    {
        return PI * banKinh * banKinh;
    }

    double chuVi()
    {
        return 2 * PI * banKinh;
    }
};

struct TamGiac
{
    double a;
    double b;
    double c;

    double chuVi()
    {
        return a + b + c;
    }

    double dienTich()
    {
        double p = chuVi() / 2;

        return sqrt(
            p * (p - a) * (p - b) * (p - c)
        );
    }
};

int main()
{
    int luaChon;

    do {
        cout << "===== MENU =====\n";
        cout << "1. Hinh vuong\n";
        cout << "2. Hinh chu nhat\n";
        cout << "3. Hinh tron\n";
        cout << "4. Tam giac\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 1:
        {
            HinhVuong hv;

            cout << "Nhap canh: ";
            cin >> hv.canh;

            cout << "Chu vi = " << hv.chuVi() << endl;
            cout << "Dien tich = " << hv.dienTich() << endl;

            break;
        }

        case 2:
        {
            HinhChuNhat hcn;

            cout << "Nhap chieu dai: ";
            cin >> hcn.dai;

            cout << "Nhap chieu rong: ";
            cin >> hcn.rong;

            cout << "Chu vi = " << hcn.chuVi() << endl;
            cout << "Dien tich = " << hcn.dienTich() << endl;

            break;
        }

        case 3:
        {
            HinhTron ht;

            cout << "Nhap ban kinh: ";
            cin >> ht.banKinh;

            cout << "Chu vi = " << ht.chuVi() << endl;
            cout << "Dien tich = " << ht.dienTich() << endl;

            break;
        }

        case 4:
        {
            TamGiac tg;

            cout << "Nhap canh a: ";
            cin >> tg.a;

            cout << "Nhap canh b: ";
            cin >> tg.b;

            cout << "Nhap canh c: ";
            cin >> tg.c;

            if (tg.a + tg.b > tg.c &&
                tg.a + tg.c > tg.b &&
                tg.b + tg.c > tg.a)
            {
                cout << "Chu vi = " << tg.chuVi() << endl;
                cout << "Dien tich = " << tg.dienTich() << endl;
            }
            else
            {
                cout << "Ba canh khong tao thanh tam giac!";
            }

            break;
        }

        default:
            cout << "Lua chon khong hop le!";
        }

    }
	while (luaChon != 0);
   

    return 0;
}