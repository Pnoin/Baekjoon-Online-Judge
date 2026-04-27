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

int n,arr[4000005]={};
vector <int> v;

void sieve(){
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i*2; j<=n; j+=i){
                arr[j]=1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            v.push_back(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    sieve();
    /*
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    */
    int start=0,end=0,cnt=0,total=v[0];
    while(true){
        if(start>end || end==v.size()){
            break;
        }
        if(total<n){
            end++;
            total+=v[end];
        }
        else if(total>n){
            total-=v[start];
            start++;
        }
        else if(total==n){
            cnt++;
            end++;
            total+=v[end];
        }
    }
    cout << cnt;
}