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
typedef pair <int,int> PII;

int n;
vector <PII> v;
priority_queue <int, vector<int>, greater<int>>  pq; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++){
    int num;
    cin >> num;
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for(int i=1; i<n; i++){
		pq.push(v[i].second);
		if(pq.top()<=v[i].first){
			pq.pop();
		}
	}
	cout << pq.size();
}