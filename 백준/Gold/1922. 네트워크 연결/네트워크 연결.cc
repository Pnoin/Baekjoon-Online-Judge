#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,m,parent[1005]={};
ll total=0;
pair<int,pair<int,int>> arr[100005];

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
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[i].first=c;
        arr[i].second.first=a;
        arr[i].second.second=b;
    }
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }
    sort(arr,arr+m);
    for(int i=0; i<m; i++){
        if(!isUnion(arr[i].second.first,arr[i].second.second)){
            total+=arr[i].first;
            Union(arr[i].second.first,arr[i].second.second);
        }
    }
    cout << total;
}