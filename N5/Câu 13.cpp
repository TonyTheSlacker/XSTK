/*
13. Write a program to calculate taxi fare with the following rates:

- The first KM: 5000đ.

- The next 200 meters: 1000đ. => 1km =  

- If the total distance is more than 30km, every additional kilometer is 3000đ.

Input the total distance and output the total amount to be paid.
*/

#include <iostream>
using namespace std;

int main() {
    double totaldistance;
    cin >> totaldistance;

    double fare = 0;

    if (totaldistance <= 0) {
        fare = 0;
    } 
    else if (totaldistance <= 30) {
        fare = totaldistance * 5000;
    } 
    else {
        fare = (30 * 5000) + ((totaldistance - 30) * 3000);
    }

    cout << "Total amount: " << fare << "d" << endl;
    return 0;
}
