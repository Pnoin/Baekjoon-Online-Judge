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

int n,total=0;

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
    if(n==1){
        cout << "1" << "\n" << "1 1";
        return 0;
    }
    cout << n*2-2 << "\n" << 1 << " " << 1 << "\n" << 1 << " " << n << "\n";
    for(int i=2; i<n; i++) {
        cout << 1 << " " << i << "\n";
        cout << n << " " << i << "\n";
    }

	/*
	finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}