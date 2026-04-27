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

int n,arr[100005][3]={},md=9901;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	/*
    clock_t start,finish;
    double duration;
    start=clock();
	*/

    cin >> n;
    arr[1][0]=1;
    arr[1][1]=1;
    arr[1][2]=1;
    for(int i=2; i<=n; i++){
        arr[i][0]=(arr[i-1][1]+arr[i-1][2])%md;
        arr[i][1]=(arr[i-1][0]+arr[i-1][2])%md;
        arr[i][2]=(arr[i-1][1]+arr[i-1][2]+arr[i-1][0])%md;
    }
    cout << (arr[n][0]+arr[n][1]+arr[n][2])%md;

	/*
	finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}