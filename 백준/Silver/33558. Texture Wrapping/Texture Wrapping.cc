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

int n,m,u,v;
char arr[205][205]={},ans[205][205]={};
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
    
    cin >> n >> m >> u >> v;
    for(int i=0; i<u; i++){
        for(int j=0; j<v; j++){
            cin >> arr[i][j];
        }
    }
    cin >> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x,y;
            if(s=="clamp-to-edge"){
                if(i<u){
                    x=i;
                }
                else{
                    x=u-1;
                }
                if(j<v){
                    y=j;
                }
                else{
                    y=v-1;
                }
            }
            else if(s=="repeat"){
                x=i%u;
                y=j%v;
            }
            else if(s=="mirrored-repeat"){
                int x_quo=i/u,y_quo=j/v,x_rem=i%u,y_rem=j%v;
                if(x_quo%2){
                    x_rem=u-x_rem-1;
                }
                if(y_quo%2){
                    y_rem=v-y_rem-1;
                }
                x=x_rem;
                y=y_rem;
            }
            ans[i][j]=arr[x][y];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}