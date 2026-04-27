#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> s;
	if(s=="miss"){
        cout << 0;
    }
	else if(s=="bad"){
        cout << n*200;
    }
	else if(s=="cool"){
        cout << n*400;
    }
	else if(s=="great"){
        cout << n*600;
    }
	else{
        cout << n*1000;
    }
}