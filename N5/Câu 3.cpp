#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 5,y;
    y=x++ + 5;
    printf("x=%d, y=%d\n", x, y);
    y *=6;
    x = y%7;
    printf("x=%d, y=%d, y/x=%d",x,y,y/x);
}