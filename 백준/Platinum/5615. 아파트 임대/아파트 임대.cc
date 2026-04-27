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
typedef long double ld;
typedef complex<double> cpx;
typedef unsigned long long int li;

li num,ans=0; 
int n,primearr[3]={2,7,61};
/*
    int의 범위 내에서는 3개의 소수들만 체크를 거치면 된다고 증명이 완료되었다함. 
    출처: https://goodbyefin.tistory.com/47
*/

li Pow(li a, li n, li p){
    li fin=1; 
    a%=p;
    while(true){
        if(n==0){
            break;
        }
        if(n%2==1){
            fin=(fin*a)%p;
        }
        n/=2;
        a=(a*a)%p;
    }
    return fin;
}

bool Miller_Rabin(li p,li a){ ///P는 항상 홀수
    if(a%p==0){
        return true;
    }
    li k=p-1; ///K의 시작 값은 항상 짝수
    while(true){
        li temp=Pow(a,k,p);
        if(temp==p-1){
            return true;    
        }
        if(k%2){
            if(temp==1 || temp==p-1){
                return true;
            }
            else{
                return false;
            }
        }
        k/=2;
    }
}

bool Prime(li p){ ///짝수는 안들어옴
    for(int i=0; i<3; i++){
        int temp=primearr[i]; 
        if(temp==p){
            return true;
        }
        if(!Miller_Rabin(p,temp)){
            return false;
        }
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(register int i=0; i<n; i++){
        cin >> num;
        if(Prime(2*num+1)){
            ans++;
        }
    }
    cout << ans;
}