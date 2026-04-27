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

int n;
bool ck[1003005]={};
vector <int> prime;

void sieve(){
    for(int i=2; i<=1003001; i++){
        if(ck[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i*2; j<=1003001; j+=i){
            ck[j]=true;
        }
    }
}

bool Palindrome(int num){
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
    sieve();
    cin >> n;
    for(int i=0; i<prime.size(); i++){
        if(prime[i]>=n){
            if(Palindrome(prime[i])){
                cout << prime[i];
                return 0;
            }
        }
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}