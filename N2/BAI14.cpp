#include <iostream>

bool isTriangle(int a, int b, int c)
{
    // Three sides a, b, c can form a triangle if they satisfy the "triangle inequality"
    return (a + b > c) and (a + c > b) and (b + c > a);
}

bool isRight(int a, int b, int c)
{
    return 
    a*a + b*b == c*c or 
    a*a + c*c == b*b or
    b*b + c*c == a*a;    
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if (isTriangle(a, b, c))
    {
        std::cout << "a ";
        if (a == b and b == c) std::cout << "Equilateral triangle (Tam giac dieu)" << std::endl;
        else if (a == b or b == c or a == c) std::cout << "Isosceles triangle (Tam giac can)" << std::endl;
        else std::cout << "Scalene triangle (Tam giac thuong)" << std::endl;

        if (isRight(a, b, c)) std::cout << "a Right triangle also (Tam giac vuong)" << std::endl;
    }
    else std::cout << "Cannot form a triangle!" << std::endl;

    return 0;
}