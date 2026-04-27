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

ll a,b,c,sy0=2014,off0=3,s0,sy1,off1,s1; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> a >> b >> c; 
	s0=sy0*4+off0; 
	if(b==1||b==2){
		sy1=a-1; 
		off1=3; 
	}
	else if(b<=5){
		sy1=a; 
		off1=0; 
	}
	else if(b<=8){
		sy1=a; 
		off1=1; 
	}
	else if(b<=11){
		sy1=a; 
		off1=2; 
	}
	else{
		sy1=a; 
		off1=3; 
	}
	s1=sy1*4+off1; 
	cout << s1-s0+1; 
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   