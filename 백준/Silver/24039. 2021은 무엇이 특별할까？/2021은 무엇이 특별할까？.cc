#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n;
vector <int> prime;
bool ck[10005]={};

void sieve(){
    for(int i=2; i<=10000; i++){
        if(ck[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i*2; j<=10000; j+=i){
            ck[j]=true;
        }
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
    cin >> n;
    sieve();
    for(int i=0; i<prime.size()-1; i++){
        if(prime[i]*prime[i+1]>n){
            cout << prime[i]*prime[i+1];
            return 0;
        }
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}