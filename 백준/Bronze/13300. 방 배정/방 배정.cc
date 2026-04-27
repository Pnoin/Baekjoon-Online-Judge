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

int n,k,arr[2][10]={},total=0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
	
	cin >> n >>k;
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		arr[a][b]++;
	}
	for(int i=0; i<2; i++){
		for(int j=1; j<7; j++){
			if(arr[i][j]!=0){
				total+=arr[i][j]/k;
				if(arr[i][j]%k!=0){
					total++;
                }
			}
		}
     }
   
	cout << total;	


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}