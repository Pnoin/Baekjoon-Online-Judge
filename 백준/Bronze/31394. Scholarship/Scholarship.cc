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
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int n,m,s=0,a=0,b=1; 

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
	for(int i=0; i<n; i++){
		cin >> m; 
		s+=m; 
		if(m==3){
			a=1; 
		}
		if(m!=5){
			b=0; 
		}
	}
	if(b){
		cout << "Named"; 
	}
	else{
		if(a){
			cout << "None"; 
		}
		else{
			double avg=(double)s/n; 
			if(avg>=4.5){
				cout << "High"; 
			}
			else{
				cout << "Common"; 
			}
		}
	}
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   