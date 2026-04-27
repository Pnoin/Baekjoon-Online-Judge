#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
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
    cin.ignore();
    for(int i=0; i<n; i++){
        string s;
        getline(cin,s);
        cout << "god";
        int idx=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]==' '){
                idx=j+1;
                break;
            }
        }
        for(int j=idx; j<s.size(); j++){
            if(s[j]==' '){
                continue;
            }
            cout << s[j];
        }
        cout << '\n';
    }
    
    
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}