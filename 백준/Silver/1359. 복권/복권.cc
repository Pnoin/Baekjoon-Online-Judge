//https://www.acmicpc.net/board/view/137286



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

int n,m,k,den,num=0;

int factorial(int x){
	if(x<2){
		return 1;
	}
	else{
		return x*factorial(x-1);
	}
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

	cin >> n >> m >> k;
	den=factorial(n)/(factorial(m)*factorial(n-m));
	for(int i=k; i<=m; i++){
    int a=factorial(m)/(factorial(i)*factorial(m-i));
    int b=factorial(n-m)/(factorial(m-i)*factorial(n-m-m+i));
		num+=a*b;
	}
	cout.precision(10);
	cout << double(num)/double(den);

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}