/*
15. Write a program that inputs a positive integer n. Check whether the n is a
perfect square(whose square root is an integer).
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = sqrt(n);
    if(i*i==n){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}