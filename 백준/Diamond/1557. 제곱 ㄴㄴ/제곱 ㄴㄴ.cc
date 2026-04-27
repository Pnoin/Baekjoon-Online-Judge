/*
    <메모>
    1016번 제곱 ㄴㄴ수와의 차이점:
    - 1016번은 특정 숫자 범위 내에서 제곱 ㄴㄴ수의 갯수를 찾는 것
    - 1557번은 K번째 제곱 ㄴㄴ수를 찾는 것

    여기서 주의해야할 것은
    1016번은 숫자의 범위가 최대 10억+100만 까지가 범위인 반면
    1557번은 K, 즉, 최대 10억번째 제곱 ㄴㄴ수를 찾아야하기 때문에 실질적으로 10억을 넘는 숫자들을 고려해야함

    1016번처럼 에라토스테네스의 체로 접근해보려했는데 소수 판정 이후의 과정을 떠올리기 힘들어 알고리즘 태그를 확인함 --> 에라토스테네스의 체가 없었음 --> 1차 멘붕
    
    뭔가 정수론적인 접근방식이 있을 거 같아서 위키피디아를 찾아봄 --> https://ko.wikipedia.org/wiki/%EC%A0%9C%EA%B3%B1_%EC%9D%B8%EC%88%98%EA%B0%80_%EC%97%86%EB%8A%94_%EC%A0%95%EC%88%98
    제곱 인수가 없는 정수에 대한 문서가 존재했음

    "양의 정수 n에 대하여, 다음 조건들이 서로 동치이며, 이를 만족시키는 양의 정수를 제곱 인수가 없는 정수라고 한다." 파트를 보니 6가지 조건들이 있던데
    이 중 하나가 μ(n) != 0 이라고 한다. 여기서 μ(n)이 무엇인가 보니 뫼비우스 함수라고 하는데 사실 오늘 처음 알게 됨

    1차 시도: https://www.geeksforgeeks.org/program-mobius-function/
    

    2차 시도: stackexchange에서 마침 이 문제와 비슷한 질문을 한 글을 찾음 https://math.stackexchange.com/questions/20529/fast-method-for-nth-squarefree-number-using-mathematica
    대충 요약하면 포함-배제 원리를 사용하여 sqrt(N)까지만의 탐색만으로 N 이하의 제곱 ㄴㄴ수를 찾는 공식을 더 간소화시킨 버전이 있다고 한다
    해당 글의 댓글을 보면 "You will need to use inclusion/exclusion, but there are only about 40,000 to consider."라는 말이 있어 대충 sqrt(2e9)=대략 45000 정도로 잡고 시도함.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 
using namespace std;

ll n,temp=0,total=0,sum=-1;
ll arr[45005]={},prime[45005]={};

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
   
    cin >> n;
	for(int i=2; i<45000; i++){
		if(!prime[i]){
            for(int j=i; j<45000; j+=i){
                if(j%(i*i)==0){
                    prime[j]=-45000;
                }
                else{
                    prime[j]++;
                }
            }
        }
	}
	for(int i=2; i<45000; i++){
		if(prime[i]>0){
            arr[temp]=i*i;
            if(prime[i]%2==0){
                arr[temp]*=-1;
            }
            temp++;
        }
    }
	ll ans=n;
	while(true){
        total=0;
        for(int i=0; arr[i]<=ans; i++){
            total+=(ans/arr[i]);
        }
        if(n==ans-total){
            break;
        }
		ans=n+total;
	}
	cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
