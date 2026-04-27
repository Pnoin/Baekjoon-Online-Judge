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
#include <unordered_set>
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

double a,b,c;
int cnt=1;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cout << fixed;
    cout.precision(3);
    while(true){
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0){
            break;
        }
        cout << "Triangle #" << cnt << '\n';
        if(a<0){
            if(c<=b){
                cout << "Impossible." << '\n';
            } 
            else{
                cout << "a = " << sqrt(c*c-b*b) << '\n';
            }
        }
        else if(b<0){
            if(c<=a){
                cout << "Impossible." << '\n';
            } 
            else{
                cout << "b = " << sqrt(c*c-a*a) << '\n';
            }
        }
        else if(c<0){
            cout << "c = " << sqrt(a*a+b*b) << '\n';
        }
        cout << '\n';
        cnt++;
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   