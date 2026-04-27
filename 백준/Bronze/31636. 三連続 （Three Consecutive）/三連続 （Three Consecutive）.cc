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
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> s;
    if(n<3){
        cout << "No";
        return 0;
    }
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='o' && s[i+1]=='o' && s[i+2]=='o'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
