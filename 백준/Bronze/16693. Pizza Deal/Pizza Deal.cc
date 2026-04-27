#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double q = c * c * M_PI / d;
    double w = a / b;
    if (q > w) {
        cout << "Whole pizza";
    }
    else {
        cout << "Slice of pizza";
    }
}