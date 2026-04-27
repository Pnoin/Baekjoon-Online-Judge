#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <regex>
#include <iomanip>
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
const ld PI=acos(-1); 
const ll INF=1e18;

int n,m,cnt=0,cur=0,arr[1000005]={};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> m; 
	for(int i=0; i<n; i++){
        cin >> arr[i];
		cur+=arr[i];
		if(i>=m){
			cur-=arr[i-m];
		}
		if(cur>= 129 && cur<=138){
			cnt++;
		}
	}
	cout << cnt;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   