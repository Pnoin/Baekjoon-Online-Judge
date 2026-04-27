/*
    <메모> 
    2024.07.27
    (i,j) 구간의 점수를 계산하는 식이 (prefix_sum[j]-prefix_sum[j-1])+(prefix_sum[j]-prefix_sum[j-2])+(prefix_sum[j]-prefix_sum[j-3])....+(prefix_sum[j]-prefix_sum[i-1])
    문제는 저걸 DP에 적용시킬 떄 어떤 식으로 식 변환을 해야하는지 고민
    어짜피 누적합 배열에 대한 누적합 배열을 하나 더 만들어서 활용하면 된다는 쪽으로 아이디어가 떠오름
    1차시도
    평소에 0스타트 인덱스를 많이 썼는데 뭔가 이렇게 하니까 헷갈리는 듯
    이 문제의 경우 점화식을 
    max(prefix_sum[n]*i*-1 + prefix_sum2[i-2]) + prefix_sum[n]*(n+1)-prefix_sum2[n-1]
    로 잡아야함
    i-2 때문에 인덱스 0 스타트를 해버리니까 i=1 경우까지 전처리해서 넣어줘야함
    귀찮다
    어짜피 큰 의미도 별 차이도 없지만 그냥 1스타트로 바꿈
    
    중간저장용 제출 1 --> WA

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

    일단 1차 시도가 틀렸던 이유 --> 지금까지 풀었던 다른 CHT문제들과는 달리 문제에서 단조성을 보장하지 않음
    결국 다른 CHT 구현 방식을 찾아 공부해봐야할 듯 
    원래 사용하던 CHT 구현 방식은 단조성이 보장되는 경우에 대하여 공간복잡도와 시간복잡도의 효율을 올린 구현방식을 씀 (Koosaga님의 방식)

    https://blog.naver.com/jinhan814/222689836982
    해당 블로그에서 Line Container파트에 있는 코드를 봄.
    이 방식으로 구현된 구현체를 쓰면 기울기 단조성이 보장되지 않더라도 CHT를 이용한 max값을 구할 수 있다고 한다. 
    이게 가장 generalise된 구현 방식으로 보임

    이 구현 방식을 공부하고 좀 더 활용해먹어야겠다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
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
const ll INF = 1e18;

ll n,prefix_sum[200005]={},prefix_sum2[200005]={},dp[200005]={};


/*  
    공부 블로그: https://blog.naver.com/jinhan814/222689836982
    코드 구현 참고 자료: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
*/

struct Line{
    mutable ll a,b,p;
    bool operator <(const Line &i)const{ 
        return a<i.a; 
    }
    bool operator <(ll x)const{ 
        return p<x; 
    }
};

struct LineContainer:multiset<Line,less<>>{
    ll Div(ll a, ll b){ 
        return (a/b)-((a^b)<0 && (a%b)!=0); 
    }
    bool intersect(iterator x, iterator y){
        if(y==end()){
            (x->p)=INF;
            return false;
        }
        if((x->a)==(y->a)){
            if((x->b)>(y->b)){
                (x->p)=INF;
            } 
            else{
                (x->p)=-INF;
            }
        } 
        else{
            (x->p)=Div((y->b)-(x->b),(x->a)-(y->a));
        }
        return (x->p)>=(y->p);
    }
    void Insert(ll a,ll b){
        //여기서 a가 기울기, b가 절편
        auto z=insert({a,b,0}),x=z,y=z;
        z++;
        while(true){
            if(!intersect(y,z)){
                break;
            }
            z=erase(z);
        }
        if(x!=begin()){
            x--;
            if(intersect(x,y)){
                y=erase(y);
                intersect(x,y);
            }
        }
        while(true){
            y=x;
            if(y==begin()){
                break;
            }
            x--;
            if((x->p)<(y->p)){
                break;
            }
            intersect(x,erase(y));
        }
    }
    ll query(ll x){
        auto l=*lower_bound(x);
        return (l.a)*x+(l.b);
    }
}CHT;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> prefix_sum[1];
    for(int i=2; i<=n; i++){
        cin >> prefix_sum[i];
        prefix_sum[i]+=prefix_sum[i-1];
    }
    prefix_sum2[1]=prefix_sum[1];
    for(int i=2; i<=n; i++){
        prefix_sum2[i]=prefix_sum[i]+prefix_sum2[i-1];
    }
    //prefix_sum2[i-2] 때문에 인덱스가 음수까지 갈 수 있기 때문에 첫번째 (1)에 대한 경우를 반복문 전에 미리 처리
    CHT.Insert(-1,0);
    dp[1]=prefix_sum[1]; //prefix_sum[1]*-1 + prefix_sum[1]*2
    for(int i=2; i<=n; i++){
        CHT.Insert(-i,prefix_sum2[i-2]);
        dp[i]=CHT.query(prefix_sum[i])+prefix_sum[i]*(i+1)-prefix_sum2[i-1];
    }   
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans=max(ans,dp[i]);
    }
    cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
