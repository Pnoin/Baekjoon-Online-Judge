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
typedef __int128_t li;

int primearr[12]={2,3,5,7,11,13,17,19,23,29,31,37}; 
/*
    long long int의 범위 내에서는 31까지의 소수들만 체크를 거치면 된다고 증명이 완료되었다함. 
    출처: https://goodbyefin.tistory.com/47
*/
ll a,b;
vector <li> ans;

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
        if(k%2==1){
            if(temp==1 or temp==p-1){
                return true;
            }
            else{
                return false;
            }
        }
        k/=2;
    }
}

bool Prime(li p){ ///짝수는 미리 걸러냄
    for(int i=0; i<12; i++){
        li temp=primearr[i]; 
        if(temp==p){
            return true;
        }
        if(!Miller_Rabin(p,temp)){
            return false;
        }
    }
    if(p<=40){
      return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for(ll i=a; i<=b; i++){ //B - A ≤ 100
        if(Prime(i) || i==9){
            cout << i << ' ';
        }
    }
}