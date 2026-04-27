#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    double m, res;
    m = (b - a);
    m /= 400;
    res = 1 / (1 + pow(10, m));
    cout << res;
}