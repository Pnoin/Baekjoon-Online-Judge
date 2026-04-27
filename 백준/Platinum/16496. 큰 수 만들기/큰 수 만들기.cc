#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#pragma GCC optimize ("O3")
typedef long long int ll;
using namespace std;

vector <string> v;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    if (v[0] == "0") {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
}