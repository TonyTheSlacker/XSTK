#include <bits/stdc++.h>
using namespace std;

int main(){
     int a=9,b=6;
     a =a + b--;
     a = a +(--b);
     
     if(a % 2 ==0)
        printf("Gia tri cua a la chan\n");
    printf("Tong cua a va b la: %d", a+b);
}