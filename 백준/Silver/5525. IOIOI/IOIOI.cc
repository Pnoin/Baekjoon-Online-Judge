
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
typedef pair <ll,ll> pll;

int n,m,ans=0;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s;
    int leng=1+(2*n);
    for(int i=0; i<=m-leng; i++){
        int cnt=0,od=0;
        if(i%2==0){
            for(int j=i; j<i+leng; j++){
                if(j%2==0 && s[j]=='I'){
                    cnt++;
                }
                else if(j%2==1 && s[j]=='O'){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        else{
            for(int j=i; j<i+leng; j++){
                if(j%2==1 && s[j]=='I'){
                    cnt++;
                }
                else if(j%2==0 && s[j]=='O'){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        if(cnt==leng){
            ans++;
        }
    }
    cout << ans;
}