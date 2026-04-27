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
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

string a,b;
int dp[1005][1005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a[i-1]!=b[j-1]){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            else{
                dp[i][j]=dp[i-1][j-1]+1;
            }
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
    int x=a.size(),y=b.size(),cnt=dp[a.size()][b.size()];
    vector <char> v;
    while(true){
        if(cnt==0){
            break;
        }
        if(dp[x][y]==dp[x-1][y]){
            x--;
        }
        else if(dp[x][y]==dp[x][y-1]){
            y--;
        }
        else{
            x--;
            y--;
            cnt--;
            v.push_back(b[y]);
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
}