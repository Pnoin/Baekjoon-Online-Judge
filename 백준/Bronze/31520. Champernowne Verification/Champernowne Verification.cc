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

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> s;
    string temp="1";
    int i=1;
    while(true){
        if(temp.size()>=s.size()){
            if(s==temp){
                cout << i;
                return 0;
            }
            else{
                cout << -1;
                return 0;
            }
        }
        i++;
        temp+=to_string(i);
    }
}