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

int a,arr[4]={},cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    a-=1000;
    for(int i=0; i<4; i++){
        cin >> arr[i];
        if(arr[i]>=a){
            cnt++;
        }
    }
    cout << cnt;
}