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

int n;
string arr[205]={};
vector <string> v;

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
    for(int test=0; test<n; test++){
        cin >> arr[test];
    }
    for(int i=0; i<n-1; i++){
        if(arr[i]!="Present!" && arr[i+1]!="Present!"){
            v.push_back(arr[i]);
        }
    }
    if(arr[n-1]!="Present!"){
        v.push_back(arr[n-1]);
    }
    if(v.size()==0){
        cout << "No Absences";
    }
    else{
        for(int i=0; i<v.size(); i++){
            cout << v[i] << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   