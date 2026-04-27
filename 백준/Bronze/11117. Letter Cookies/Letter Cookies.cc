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

int t,n,arr[26]={},brr[26]={};
string s,w;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> t;
    for(int test=0; test<t; test++){
        cin >> s >> n;
        memset(arr,0,sizeof(arr));
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'A']++;
        }
        for(int i=0; i<n; i++){
            cin >> w;
            memset(brr,0,sizeof(brr));
            for(int j=0; j<w.size(); j++){
                brr[w[j]-'A']++;
            }
            int temp=1;
            for(int j=0; j<26; j++){
                if(arr[j]<brr[j]){
                    temp=0;
                    break;
                }
            }
            if(temp){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }
    

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   