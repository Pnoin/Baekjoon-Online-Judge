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
string grid[30]={};

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
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
    for(int i=0; i<n; i++){
        int countB=0,countW=0;
        for(int j=0; j<n; j++){
            if(grid[i][j]=='B'){
                countB++;
            }
            else{
                countW++;
            }
        }
        if(countB!=countW){
            cout << 0;
            return 0;
        }
    } 
    for(int j=0; j<n; j++){
        int countB=0,countW=0;
        for(int i=0; i<n; i++){
            if(grid[i][j]=='B'){
                countB++;
            }
            else{
                countW++;
            }
        }
        if(countB!=countW){
            cout << 0;
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-3; j++){
            if(grid[i][j]==grid[i][j+1] && grid[i][j]==grid[i][j+2]){
                cout << 0;
                return 0;
            }
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<=n-3; i++){
            if(grid[i][j]==grid[i+1][j] && grid[i][j]==grid[i+2][j]){
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   