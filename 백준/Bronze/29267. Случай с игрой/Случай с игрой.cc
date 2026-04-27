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

int n,k,curr_ammo=0,saved_ammo=-1;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> k;
    for(int i=0; i<n; i++){
        string cmd;
        cin >> cmd;
        if(cmd=="save"){
            saved_ammo=curr_ammo;
        }
        else if(cmd=="load"){
            if(saved_ammo<0){
                curr_ammo=0;
            }
            else{
                curr_ammo=saved_ammo;
            }
        }
        else if(cmd=="shoot"){
            curr_ammo--;
        }
        else if(cmd=="ammo"){
            curr_ammo+=k;
        }
        cout << curr_ammo << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   