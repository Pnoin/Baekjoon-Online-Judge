#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
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
    cout << s[0];
    int next=0;
    next=s[0]-'A'+1;
    while(true){
        if(next>=s.size()){
            break;
        }
        cout << s[next];
        next+=s[next]-'A'+1;
    }

}