#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,total=0,stan; 
vector <int> vi;
vector <string> vs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        int m;
        cin >> s >> m;
        if(s=="jinju"){
            stan=m;
        }
        vs.push_back(s);
        vi.push_back(m);
    }
    for(int i=0; i<n; i++){
        if(vi[i]>stan){
            total++;
        }
    }
    cout << stan << '\n' << total;
}