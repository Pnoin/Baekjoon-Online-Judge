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
             
    cin >> n;
    s.reserve(n);
    cin >> s;  
    int cur=n,cnt=0;
    while(true){
        if(cur<=1){
            break;
        }
        if(s[cur-1]=='0'){
            cur--;
        } 
        else{
            int i=cur-1;
            while(true){
                if(i<0 || s[i]!='1'){
                    break;
                }
                s[i]='0';
                i--;
            }
            if(i>=0){
                s[i]='1';
            } 
            else{   
                s[0]='1';
            }
            cur--;
            cnt++;
        }
    }
    cout << cnt;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   