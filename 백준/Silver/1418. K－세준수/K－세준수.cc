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

int n,k,cnt=0;
vector <int> prime;
int ck[100005]={};
bool ck2[100005]={};

void sieve(){
    for(int i=2; i<=100000; i++){
        if(ck2[i]){
            continue;
        }
        for(int j=i; j<=100000; j+=i){
            ck[j]=i;
            ck2[j]=true;
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
    cin >> n >> k;
    sieve();
    for(int i=1; i<=n; i++){
        if(ck[i]<=k){
            cnt++;
        }
    }
    cout << cnt;
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}