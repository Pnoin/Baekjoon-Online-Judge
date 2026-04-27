/// 큰 수 곱셈 2에서 사용했던 코드를 조금 더 최적화하는 과정을 거침
/// 아래의 적힌 주석들은 큰 수 곱셈 2에 해당됨. 

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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,md=1e9;
ll arr[1000005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i]+=arr[i-1];
        if(i%2==0){
            arr[i]+=arr[i/2];
        }
        arr[i]%=md;
    }
    cout << arr[n];
}