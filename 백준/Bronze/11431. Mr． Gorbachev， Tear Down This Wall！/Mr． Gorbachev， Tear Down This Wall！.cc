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

int t,n,m,k;
pair <ld,ld> arr[1005];
ld total=0;

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
    for(int test=1; test<=t; test++){
        cin >> n >> m >> k;
        memset(arr,0,sizeof(0));
        for(int i=0; i<=n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        total=0;
        for(int i=1; i<=n; i++){
            if(arr[i-1].first==arr[i].first){
                total+=abs(arr[i-1].second-arr[i].second);
            }
            else{
                total+=abs(arr[i-1].first-arr[i].first);
            }
        }
        cout << "Data Set " << test << ": " << '\n';
        cout << ceil(total*m/k) << '\n' << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   