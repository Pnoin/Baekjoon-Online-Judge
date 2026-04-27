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

int n,m,parent[500005]={},ans=0,fin=0; 

int Find(int x) {
	if(x==parent[x]){
        return x;
    }
	return parent[x]=Find(parent[x]);
}

void Union(int x,int y) {
	x=Find(x);
	y=Find(y);
	if(x==y){
        return;
    }
	if(x<y){
        parent[y]=x;
    }
	else{
        parent[x]=y;
    }
}

bool isUnion(int x,int y) {
	x=Find(x);
	y=Find(y);
	return (x==y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
		parent[i]=i;
    }
	for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        if(!isUnion(x,y)){
            Union(x,y);
        }
        else{
            if(fin==0){
                fin=1;
                ans=i+1;
            }
        }
    }
    cout << ans;
} 