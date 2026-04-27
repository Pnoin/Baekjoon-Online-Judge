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

string s;

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
    string best=string(100,'z');
    for(int i=0; i+2<s.size(); i++){
        for(int j=i+1; j+1<s.size(); j++){
            string a=s.substr(0,i+1);
            string b=s.substr(i+1,j-i);
            string c=s.substr(j+1);
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            reverse(c.begin(),c.end());
            string t=a+b+c;
            if(t<best){
                best=t;
            }
        }
    }
    cout << best;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   