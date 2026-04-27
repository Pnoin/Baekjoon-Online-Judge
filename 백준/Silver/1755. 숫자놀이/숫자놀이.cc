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

int m,n,cnt=0;
string word[10]={"zero", "one", "two",   "three", "four","five", "six", "seven", "eight", "nine"};
vector <pair<string,int>> v;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> m >> n;
    v.reserve(n-m+1);
    for(int i=m; i<=n; i++){
        string key;
        if(i<10){
            key=word[i];
        } 
        else{
            key=word[i/10]+" "+word[i%10];
        }
        v.emplace_back(key,i);
    }
    sort(v.begin(),v.end(),[](auto &a,auto &b){return a.first<b.first;});
    for(auto &p:v){
        cout << p.second;
        cnt++;
        if(cnt%10==0){
            cout << '\n';
        } 
        else if(cnt<(int)v.size()){
            cout << ' ';
        }
    }
    if(cnt%10){
        cout << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   