#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    int x=0;
    ///소수점 아래 숫자의 갯수 = string.size() - 2 (앞에 2 문자는 0과 .)
    int cnt=1;
    for(int i=s.size()-1; i>=2; i--){
        x+=(s[i]-48)*cnt;
        cnt*=10;
    }
    cout << "YES" << '\n' << x << ' ' << cnt;
}