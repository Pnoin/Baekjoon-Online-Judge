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

int n,total=0;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

	while(true){
        cin >> n;
        if(n==-1){
            break;
        }
        v.clear();
        total=0;
        for(int i=1; i<sqrt(n); i++){
            if(n%i==0){
                total+=i+(n/i);
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        if(total-n!=n){
            cout << n << " is NOT perfect." << '\n';
        }
        else{
            sort(v.begin(),v.end());
            cout << n << " = ";
            for(int i=0; i<v.size()-2; i++){
                cout << v[i] << " + ";
            }
            cout << v[v.size()-2] << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   