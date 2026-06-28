#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int tram = n / 100;
    int chuc = (n / 10) % 10;
    int donvi = n % 10;

    int max = tram;
    string vitri = "tram";

    if (chuc > max) {
        max = chuc;
        vitri = "chuc";
    }
    if (donvi > max) {
        max = donvi;
        vitri = "donvi";
    }
    cout << max;
    cout << "\nVi tri cua so lon nhat la: " << vitri;
    return 0;
}