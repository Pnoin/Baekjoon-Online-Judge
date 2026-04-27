#include <iostream>
using namespace std;

int main(){
    int n, total = 0;
    string s, q;
    cin >> s >> n;
    for(int i=0; i<n; i++) { 
        cin >> q;
        if (s == q) {
            total++;
        }
    }
    cout << total;
}