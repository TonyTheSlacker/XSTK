#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int chon;
    cin>>chon;
    switch(chon){
        case 1:{
            double a,b,c,cv,p,dt;
            cin>>a>>b>>c;
            if(a>=0&&b>=0&&c>=0&&a<b+c&&b<a+c&&c<a+b){
            cv = a+b+c;
            p=cv/2;
            dt=sqrt(p*(p-a)*(p-b)*(p-c));
            cout<<"Chu vi "<<cv<<endl<<"dien tich:"<<" "<<dt;}
            else{cout<<"khong la tam giac";}
            break;
        }
        case 2:{
            double a,b,cv,dt;
            cin>>a>>b;
            if(a>=0&&b>=0){
            cv=2*(a+b);
            dt=a*b;
            cout<<"chu vi hinh chu nhat:"<<cv<<endl<<"dien tich hinh chu nhat:"<<dt;}
            else{cout<<"khong la hinh chu nhat";}
            break;
        }
        case 3:{
            double a,cv,dt;
            cin>>a;
            if(a>=0){
            cv=a*4;
            dt=a*a;
            cout<<"chu vi hinh vuong:"<<" "<<cv<<endl<<"dien tich hinh vuong"<<" "<<dt;}
            else{cout<<"khong la hinh vuong";}
            break;
        }
        case 4:{
            double r,cv,dt;
            cin>>r;
            const double pi = 3.141592653589793;
            if(r>=0){
            cv=2*pi*r;
            dt=pi*r*r;
            cout<<"chu vi hinh tron:"<<" "<<cv<<endl<<"dien tich hinh tron:"<<" "<<dt;}
            else{cout<<"khong la hinh tron";}
            break;
        }
        default:{cout<<"khong hop le";}
    }
    return 0;
}
