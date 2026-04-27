/* 
  4149번 큰 수 소인수분해 에서 사용했던 폴라드 로 알고리즘 코드
  소인수분해를 이용한 약수의 개수 구하는 방법: https://mathbang.net/201#gsc.tab=0
*/


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
ll n,cnt=1;
vector <ll> ans;

li gcd(li x,li y){ ///유클리드 호제법
    if(x<y){
      return gcd(y,x);
    }
    li z;   
    while(y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

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

bool Prime(li p){ ///짝수는 폴라드에서 걸러내짐
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

li f(li x, li c){
    li temp=(x*x+c)%n;
    return temp;
}


/*
    자료 출처: https://blog.naver.com/jinhan814/222141831551
*/
void Pollard(li n) {
    if(n==1){
        return;
    }
    if(n%2==0){ /// 짝수를 걸러내어 2의 거듭제곱 인수를 최대한 빼놓음
        ans.push_back(2);
        Pollard(n/2);
        return;
    }
    if(Prime(n)){ /// 폴라드 로는 소수에게는 사용할 수 없으며, 소수는 더 이상 소인수분해를 적용시킬 수가 없기 때문에 그대로 최종 벡터에 집어넣고 함수를 종료
        ans.push_back((ll)n);
        return;
    }
    /// 함수 f(x) = x^2 + c
    li a,b,c;
    li g=n;
    while(true){
        if(g==n){
            a=rand()%(n-2)+2;
            b=a;
            c=rand()%10+1;
        }   
        /*
            비둘기 집의 원리를 통해 사이클이 형성될 것임이 증명됨
            사이클이 존재하는 상태에서 플로이드 순환 찾기 알고리즘을 사용하면
            각 연산마다 f를 한 번 적용하는 a와 f를 2번 적용하는 b는 연산이 진행될 때마다 값이 겹쳐질 때의 상태로 점점 다가감
        */
        a=f(a,c);
        b=f(f(b,c),c);
        g=gcd(abs(a-b),n);
        if(g!=1){ /// gcd가 1이 아니라는 소리는 abs(a-b)가 n의 약수 중 하나라는 소리
            break;
        }
    }
    Pollard(g);
    Pollard(n/g);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    Pollard((li)n);
    sort(ans.begin(),ans.end());
    /// 소수의 개수 = 각 소인수의 지수 + 1의 곱
    for(int i=0; i<ans.size(); i++){
        cnt*=( ( upper_bound(ans.begin(),ans.end(),ans[i]) - ans.begin() ) - ( lower_bound(ans.begin(),ans.end(),ans[i]) - ans.begin() )) + 1;
        i=(upper_bound(ans.begin(),ans.end(),ans[i])-ans.begin())-1;
    }
    cout << cnt;
}