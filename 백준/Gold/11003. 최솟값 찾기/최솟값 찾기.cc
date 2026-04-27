/*
    처음에 N=5000000 이길래 nlogn 풀이법이면 2.4초 내에 가능할 거라고 생각해서 세그먼트 트리로 구현했으나
    재귀의 특성을 제대로 숙지하지 못했던지라 그대로 시간초과를 받음.
    세그트리로의 접근 자체는 틀리지 않았다고 생각하여, 재귀 말고 비재귀로 세그트리를 구현할 수 있는가 찾아봄. 

    https://velog.io/@statco19/segment-tree-non-recursive
    세그트리도 더 빠른 버전이 있다는 걸 알고 좀 놀랐다
    이 버전의 세그트리도 더 자주 이용해봐야겠다
*/

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

int n,l;

void seg_tree(vector <ll> &tree) {
	for(int i=n-1; i>0; --i) {
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }
}

ll query(vector <ll> &tree, int left, int right) {
	ll res=1e9;
	for(left+=n, right+=n; left < right; left >>= 1, right >>= 1) {
		if(left%2==1){
            res=min(tree[left++],res);
        }
		if(right%2==1){
            res=min(tree[--right],res);
        }
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    vector <ll> tree(n*2);
    for(int i=n; i<n*2; i++){
        cin >> tree[i];
    }
    seg_tree(tree);
    for(int i=0; i<n; i++){
        if(i-l+1<0){
            cout << query(tree, 0, i+1) << ' ';
        }
        else{
            cout << query(tree, i-l+1, i+1) << ' ';
        }
    }
}