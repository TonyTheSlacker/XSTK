/*
14. Input 3 positive integers a, b, c. Check whether those numbers can form a
triangle. If so, determine what type of triangle it is?(isosceles, right, equilateral,
etc.).
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b && b==c && a==c){
        cout << "equilateral";
    }
    else if(a==b || b==c || a==c){
        cout << "isosceles";
    }
    else{
        cout << "scalene";
    }


    return 0;
}