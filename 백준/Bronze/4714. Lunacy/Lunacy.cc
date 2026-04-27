#include <iostream>
using namespace std;

int main() {
    while (true) {
        double x;
        cin >> x;
        if (x < 0) {
            break;
        }
        cout << fixed;
        cout.precision(2);
        cout << "Objects weighing " << x << " on Earth will weigh " << x * 0.167 << " on the moon." << '\n';
    }
}