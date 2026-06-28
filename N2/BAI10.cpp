#include <iostream>
using namespace std;
int main(){
    int gio,phut,giay;
    cin>>gio>>phut>>giay;
    if(gio>=0&&gio<24&&phut>=00&&phut<60&&giay>=00&&giay<60){cout<<"YES"<<endl<<gio<<":"<<phut<<":"<<giay;}
    else{cout<<"NO";}
    return 0;
}
