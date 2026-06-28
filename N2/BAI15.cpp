#include <iostream>
#include <cmath>

int main()
{
    int n; std::cin >> n;

    if (n <= 0) 
    {
        std::cout << "Vui long nhap so nguyen!" << std::endl;
        return 0;
    }
    
    int root = sqrt(n);
    if (root * root == n) std::cout << n << " la SCP" << std::endl;
    else std::cout << n << " khong la SCP" << std::endl;

    return 0;
}