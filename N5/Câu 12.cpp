#include <iostream>
#include <cmath>

using namespace std;

float area(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
float area(float a) {
    return a * a;
}
float area(float a, float b) {
    return a * b;
}
float area(float r) {
    return 3.14 * r * r;
}

float perimeter(float a, float b, float c) {
    return a + b + c;
}
float perimeter(float a) {
    return 4 * a;
}
float perimeter(float a, float b) {
    return 2 * (a + b);
}
float perimeter(float r) {
    return 2 * 3.14 * r;
}   

int main() {
    int choice;
    cout << "Choose a shape: 1. Triangle 2. Square 3. Rectangle 4. Circle: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            float a, b, c;
            cout << "Enter the sides of the triangle: ";
            cin >> a >> b >> c;
            cout << "Area: " << area(a, b, c) << endl;
            cout << "Perimeter: " << perimeter(a, b, c) << endl;
            break;
        }
        case 2: {
            float a;
            cout << "Enter the side of the square: ";
            cin >> a;
            cout << "Area: " << area(a) << endl;
            cout << "Perimeter: " << perimeter(a) << endl;
            break;
        }
        case 3: {
            float a, b;
            cout << "Enter the sides of the rectangle: ";
            cin >> a >> b;
            cout << "Area: " << area(a, b) << endl;
            cout << "Perimeter: " << perimeter(a, b) << endl;
            break;
        }
        case 4: {
            float r;
            cout << "Enter the radius of the circle: ";
            cin >> r;
            cout << "Area: " << area(r) << endl;
            cout << "Perimeter: " << perimeter(r) << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}