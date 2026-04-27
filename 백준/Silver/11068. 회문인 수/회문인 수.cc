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

int t,digits[64]={};

bool is_palindrome_in_base(int num,int base){
    int len=0;
    while(num){
        digits[len++]=num%base;
        num/=base;
    }
    for(int i=0; i<len/2; i++){
        if(digits[i]!=digits[len-1-i]){
            return false;
        }
    }
    return true;
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

    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int ok=0;
        for(int base=2; base<=64; base++){
            if(is_palindrome_in_base(n,base)){
                ok=1;
                break;
            }
        }
        cout << ok << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   