#include <iostream>
using namespace std;

int main(){
    int p, q;
    cin >> p >> q;
    if (p <= 50 and q <= 10){
        cout << "White";
    }
    else if (q > 30) {
        cout << "Red";
    }
    else {
        cout << "Yellow";
    }
}