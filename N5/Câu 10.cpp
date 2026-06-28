#include <iostream>
using namespace std;
struct Time{
    int hour;
    int minute;
    int second;
};

bool checkValid(Time t) {
    if (t.hour < 0 || t.hour > 23) {
        return false;
    }
    if (t.minute < 0 || t.minute > 59) {
        return false;
    }
    if (t.second < 0 || t.second > 59) {
        return false;
    }
    return true;
}
int main() {
    Time t;
    cin>> t.hour >> t.minute >> t.second;
    cout << (checkValid(t) ? "Valid" : "Invalid") << endl;
    return 0;
}
