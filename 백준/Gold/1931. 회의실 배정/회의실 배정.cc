#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#pragma GCC optimize("O3")
using namespace std;

vector <pair <int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), cmp);
	int e=v[0].second,cnt=1;
	for(int i=1; i<n; i++){
		if(v[i].first>=e){
			cnt++;
			e=v[i].second;
		}
	}
	cout << cnt;
}