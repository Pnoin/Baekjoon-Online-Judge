// 놓쳤던 포인트: 소수 md가 1e9+7이라 이항 계수 4에서 구현한 뤼카 정리를 바로 적용할 수 없음
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
const long double PI = acos(-1); 

int t,md=1e9+7;
ll n,k,fact[4000005]={};

// 비고) 조합은 나눗셈을 사용함으로, 연산 도중에 모듈로 연산을 시도할 경우 곱셈 역원을 사용해야함
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    fact[0]=1;
    for(int i=1; i<=4000000; i++){
        fact[i]=(fact[i-1]*i)%md;
    }
    for(int test=0; test<t; test++){
        cin >> n >> k;
        ll temp=1,left=fact[n-k]*fact[k]%md,right=md-2;
        while(true){
            if(right==0){
                break;
            }
            if(right%2){
                temp*=left;
                temp%=md;
            }
            left*=left;
            left%=md;
            right/=2;
        }
        cout << fact[n]*temp%md<< '\n';
    }
}