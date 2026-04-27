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

ll n, m, p, arr[505][505]={}, ans=1;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector <ll> v;
    for(int i=0; i<n; i++){
        v.clear();
        for(int j=0; j<m; j++){
            v.push_back(arr[i][j]);
        }
        sort(v.begin(), v.end());
        int cnt=0;
        for(int j=0; j<m; j++){
            if(v[j]==-1){
                cnt++;
            }
            else{
                if(v[j]<=p){
                    p+=v[j];
                }
                else{
                    if(cnt>0){
                        while(true){
                            if(v[j]<=p || cnt==0){
                                break;
                            }
                            cnt--;
                            p*=2;
                        }
                    }
                    if(v[j]>p){
                        ans=0;
                    }
                    else{
                        p+=v[j];
                    }
                }
            }
        }
        for(int j=0; j<cnt; j++){
            p*=2;
        }
    }
    cout << ans;
}