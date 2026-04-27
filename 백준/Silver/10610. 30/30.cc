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

char arr[100005]={};
int ck=0,sum=0;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> s;
    for(int i=0; i<s.size(); i++){
        arr[i]=s[i];
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            ck=1;
        }
        sum+=s[i]-'0';
    }
    if(ck==0 || sum%3){
        cout << -1;
        return 0;
    }
    sort(arr,arr+s.size());
    for(int i=s.size()-1; i>=0; i--){
        cout << arr[i];
    }
}