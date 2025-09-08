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

int h; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
 
	cin >> h; 
	if(h==0){
		cout << 1; 
        return 0;
	}
    if(h==1){
		cout << 0; 
        return 0;
	}
    if(h%2==0){
        for(int i=0; i<h/2; i++){
            cout << '8'; 
        }
    }
    else{
        cout << '4'; 
        for(int i=0; i<(h-1)/2; i++){
            cout << '8'; 
        }
    }
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   