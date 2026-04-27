#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n;
queue <int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	while(true){
		if(q.size()==1){
			break;
		}
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}