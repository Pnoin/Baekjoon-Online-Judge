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

int n,a[100005]={},b[100005]={};
unordered_map <int,int> countA,countB;

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
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        countA[a[i]]++;
        countB[b[i]]++;
    }
    vector <int> match_pairs,lefta,leftb;   
    for(auto i:countA){
        int x=i.first,cntA=i.second,cntB=countB[x]; 
        int matches=min(cntA,cntB);
        for(int i=0; i<matches; i++){
            match_pairs.push_back(x);
        }
        for(int i=0; i<cntA-matches; i++){
            lefta.push_back(x);
        }
    }
    for(auto i:countB){
        int x=i.first,cntB=i.second,cntA=countA[x];
        int matches=min(cntA,cntB);
        for(int i=0; i<cntB-matches; i++){
            leftb.push_back(x);
        }
    }
    int match_cnt=match_pairs.size();
    vector <int> aprime,bprime;
    aprime.reserve(n);
    bprime.reserve(n);
    for(int x:match_pairs){
        aprime.push_back(x);
        bprime.push_back(x);
    }
    for(int x:lefta){
        aprime.push_back(x);
    }
    for(int x:leftb){
        bprime.push_back(x);
    }
    cout << match_cnt << '\n';
    for(int i=0; i<n; i++){
        cout << aprime[i];
        if(i==n-1){
            cout << '\n';
        }
        else{
            cout << ' ';
        }
    }
    for(int i=0; i<n; i++){
        cout << bprime[i];
        if(i==n-1){
            cout << '\n';
        }
        else{
            cout << ' ';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}