#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,m,num;
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
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<m; i++){
        cin >> num;
        if(binary_search(v.begin(),v.end(),num)){
            cout << lower_bound(v.begin(),v.end(),num)-v.begin() << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}