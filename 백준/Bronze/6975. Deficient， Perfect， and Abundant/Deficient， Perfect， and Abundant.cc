#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
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
const double PI = acos(-1); 
const ll INF = 1e18;

int t,n;

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
        cin >> n;
        int sum = 1;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                if(i*i!=n){
                    sum+=i+n/i;
                }
                else{
                    sum+=i;
                }
            }
        }

        if(sum<n){
            cout << n << " is a deficient number.\n";
        }
        else if(sum==n){
            cout << n << " is a perfect number.\n";
        }
        else{
            cout << n << " is an abundant number.\n";
        }
        if(test!=t-1){
            cout << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
