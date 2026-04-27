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

int cnt1=0,cnt2=0,arr[505]={},temp1=0,temp2=0;
string s,ans="";

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i=s.size()-1; i>=0,temp1!=cnt1/2; i--){
        if(s[i]=='0'){
            arr[i]=1;
            temp1++;
        }
    }
    for(int i=0; i<s.size(),temp2!=cnt2/2; i++) {
        if(s[i]=='1'){
            arr[i]=1;
            temp2++;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(arr[i]==0){
            ans+=s[i];
        }
    }
    
    cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   