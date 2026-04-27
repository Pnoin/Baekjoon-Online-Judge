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

int runs1[9]={},runs2[9]={},score1=0,score2=0;
bool was_ahead=false;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    for(int i=0; i<9; i++){
        cin >> runs1[i];
    }
    for(int i=0; i<9; i++){
        cin >> runs2[i];
    }
    for(int i=0; i<9; i++){
        score1+=runs1[i];
        if(score1>score2){
            was_ahead=true;
        }
        score2+=runs2[i];
        if(score1>score2){
            was_ahead=true;
        }
    }
    if(was_ahead){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   