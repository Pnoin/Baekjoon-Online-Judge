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

int t;
ll n;

bool Palindrome(ll num){
    string s=to_string(num);
    for(int i=0; i<s.size()/2; i++){
        if(s[i]!=s[s.size()-i-1]){
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
    for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
        cin >> n;
        int cnt=0;
        for(ll j=1; j<sqrt(n); j++){
            if(n%j==0){
                if(Palindrome(j)){
                    cnt++;
                }
                if(Palindrome(n/j)){
                    cnt++;
                }
            }
        }
        if((ll)sqrt(n)*(ll)sqrt(n)==n){
            if(Palindrome((ll)sqrt(n))){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}