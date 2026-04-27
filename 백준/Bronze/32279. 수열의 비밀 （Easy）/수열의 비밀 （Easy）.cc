#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <unordered_map>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 
const ll INF = 1e18;

int n,p,q,r,s,a,arr[100005]={},total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	/*
    clock_t start,finish;
    double duration;
    start=clock();
	*/
    
    cin >> n >> p >> q >> r >> s >> a;
	for(int i=1; i<=n; i++){
        if(i==1){
            arr[i]=a;
            continue;
        }
        if(i%2==0){
            arr[i]=(p*arr[i/2])+q;
        } 
		else{
            arr[i]=(r*arr[i/2])+s;
        }
    }
    for(int i=1; i<=n; i++){
        total+=arr[i];
    }

    cout << total;

	/*
	finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}