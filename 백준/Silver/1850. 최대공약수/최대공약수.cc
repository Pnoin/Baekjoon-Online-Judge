#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize ("O3")
typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) {

    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll x, y, q;
	cin >> x >> y;
    if (x > y) {
        q = gcd(x, y);
    }
    else {
        q = gcd(y, x);
    }
    for (int i = 0; i < q; i++) {
        cout << 1;
    }
}