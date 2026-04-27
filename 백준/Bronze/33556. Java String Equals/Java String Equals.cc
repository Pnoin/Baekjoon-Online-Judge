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

string a,b;

string toLowerCase(string& s){
    string lo=s;
    transform(lo.begin(),lo.end(),lo.begin(),::tolower);
    return lo;
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
    
    cin >> a >> b;
    if(a=="null"){
        cout << "NullPointerException" << '\n';
    } 
    else{
        if(b=="null"){
            cout << "false" << '\n';
        } 
        else{
            if(a==b){
                cout << "true" << '\n';
            } 
            else{
                cout << "false" << '\n';
            }
        }
    }

    if(a=="null"){
        cout << "NullPointerException" << '\n';
    } 
    else{
        if(b=="null"){
            cout << "false" << '\n';
        } 
        else{
            if(toLowerCase(a)==toLowerCase(b)){
                cout << "true" << '\n';
            } 
            else{
                cout << "false" << '\n';
            }
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}