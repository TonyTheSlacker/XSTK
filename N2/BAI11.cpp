#include <iostream>
using namespace std;
int main(){
    int ngay,thang,nam;
    cin>>ngay>>thang>>nam;
    if(nam%400==0 || (nam%4==0&&nam%100!=0)){cout<<"nam nhuan";}
    else{cout<<"Khong la nam nhuan";}
    return 0;
}
