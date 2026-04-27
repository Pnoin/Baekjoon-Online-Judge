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

int n;
char m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int cnt=1,num=1;
    while(true){
        int ck=0;
        string s=to_string(num);
        for(int i=0; i<s.size(); i++){
            if(s[i]==m){
                ck=1;
                break;
            }
        }
        if(ck==1){
            num++;
        }
        else{
            if(cnt==n){
                break;
            }
            cnt++;
            num++;
        }
    }
    cout << num;
}