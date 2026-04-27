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
    cout << n << ": " << '\n';
    for(int i=2; i<=n; i++){
        int cnt=1;
        while(true){
            if(cnt>i || i+cnt>n){
                break;
            }      
            if(abs(i-cnt)>1){
                cnt++;
                continue;
            }
            int total=0;
            while(true){
                if(total+i<=n){
                    total+=i;
                }
                else{
                    break;
                }
                if(total+cnt<=n){
                    total+=cnt;
                }
                else{
                    break;
                }
            }
            if(total==n){
                cout << i << "," << cnt << '\n';
            }
            cnt++;
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   