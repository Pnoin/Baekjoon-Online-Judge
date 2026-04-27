/*
    <메모> 
    
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
#include <map>
#include <unordered_map>
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

ll n,arr[300005]={},prefix_sum[300005]={},dp[300005]={},dp2[300005]={};

/*  
    CHT Line Container 코드 구현 참고 자료: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
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

    cin >> n >> arr[1];
    prefix_sum[1]=arr[1];
    for(int i=2; i<=n; i++){
        cin >> arr[i];
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    CHT.Insert(-arr[n],arr[n]*n-prefix_sum[n-1]);
    for(int i=n-1; i>=1; i--){
        dp[i]=CHT.query(i)+prefix_sum[i-1]+prefix_sum[n];
        CHT.Insert(-arr[i],-prefix_sum[i-1]+i*arr[i]);
    }   
    ll ans=-INF;
    for(int i=1; i<n; i++){
        ans=max(ans,dp[i]);
    }
    cout << ans << '\n';

    reverse(arr+1,arr+n+1);
    CHT.clear();
    prefix_sum[1]=arr[1];
    for(int i=2; i<=n; i++){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    CHT.Insert(-arr[n],arr[n]*n-prefix_sum[n-1]);
    for(int i=n-1; i>=1; i--){
        dp2[i]=CHT.query(i)+prefix_sum[i-1]+prefix_sum[n];
        CHT.Insert(-arr[i],-prefix_sum[i-1]+i*arr[i]);
    }   
    ans=-INF;
    for(int i=1; i<n; i++){
        ans=max(ans,dp2[i]);
    }
    cout << ans << '\n';

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
