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

ll n,arr[5005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    ll lo=0, hi=0, idx=0, mn=3e9;
    for(int i=0; i<n-2; i++){
        int start=i+1, end=n-1; 
        while(true){
            if(start>=end){
                break;
            }
            if(abs(arr[start]+arr[end]+arr[i])<=mn){
                mn=abs(arr[start]+arr[end]+arr[i]);
                lo=arr[start];
                hi=arr[end];
                idx=arr[i];
            }
            if(arr[start]+arr[end]+arr[i]==0){
                break;
            }
            else if(arr[start]+arr[end]+arr[i]>0){
                end--;
            }
            else{
                start++;
            }
        }
    }
    vector <ll> ans;
    ans.push_back(lo);
    ans.push_back(hi);
    ans.push_back(idx);
    sort(ans.begin(),ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}