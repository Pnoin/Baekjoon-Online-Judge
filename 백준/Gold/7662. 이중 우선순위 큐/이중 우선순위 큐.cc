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

multiset <int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        int k = 0, num;
        char c;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c >> num;
            if (c == 'I') {
                pq.insert(num);
            }
            else {
                if (!pq.empty()) {
                    if (num == -1) {
                        pq.erase(pq.begin());
                    }
                    else {
                        auto last = pq.end();
                        last--;
                        pq.erase(last);
                    }
                }
            }
        }
        if (pq.size() == 0) {
            cout << "EMPTY" << '\n';
        }
        else {
            auto mx = pq.end();
            mx--;
            cout << *mx << ' ' << *pq.begin() << '\n';
        }
        pq.clear();
    }
}