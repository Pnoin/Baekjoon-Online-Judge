//https://www.nayuki.io/page/barrett-reduction-algorithm
//https://www.acmicpc.net/board/view/160580

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

int t1,v1,t2,v2; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> t1 >> v1 >> t2 >> v2; 
	if(t2<0 && v2>=10){
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!"; 
	}
	else{
		if(t2<t1){
			cout << "MCHS warns! Low temperature is expected tomorrow."; 
		}
		else{
			if(v2>v1){
				cout << "MCHS warns! Strong wind is expected tomorrow."; 
			}
			else{
				cout << "No message"; 
			}
		}
	}
	
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   