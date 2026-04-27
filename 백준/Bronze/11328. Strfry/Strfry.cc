#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

int n,arr[30]={};
string a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        string ans="Possible";
        memset(arr,0,sizeof(arr));
        for(int i=0; i<a.size(); i++){
            arr[a[i]-'a']++;
        }
        for(int i=0; i<b.size(); i++){
            arr[b[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i]!=0){
                ans="Impossible";
                break;
            }
        }
        cout << ans << '\n';
    }
}