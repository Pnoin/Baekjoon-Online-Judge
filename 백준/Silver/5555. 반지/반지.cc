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
int n,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> n;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        temp=temp+temp;
        for(int i=0; i<10; i++){
            int ck=0;
            for(int j=0; j<s.size(); j++){
                if(temp[i+j]==s[j]){
                    ck++;
                }
            }
            if(ck==s.size()){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
} 