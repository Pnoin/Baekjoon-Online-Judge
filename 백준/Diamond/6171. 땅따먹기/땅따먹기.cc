/*
    <메모>
    2024.07.18
    문제: "여러 개의 땅을 살 때는, (해당 땅 중 Wi의 최댓값) * (해당 땅 중 Hi의 최댓값) 으로 가격을 매긴다." -> 여기서 최솟값 찾기

    일단 점화식에 영향을 줄 요소가 W와 H 두 가지인데
    CHT를 적용하려면 우선 일차함수 꼴로 변경하였을 때 기울기가 단조 증가/감소 하는 형태로 나와야되는 조건이 있음
    이 문제에서는 최솟값을 구하는 게 목표니 기울기가 단조 감소하기만 하면 됨

    일차함수의 기본꼴 f(x)=mx+c
    일단 H나 W를 확정적으로 단조 감소 형태로 만드는 법이 있음 --> 정렬하면 됨
    pair 형태로 입력 받을 것이니 first를 기준으로 정렬 시킨 후, first를 기울기로 놓자
    이 문제의 점화식을 dp[i]=dp[j-1]+w[i]*h[j] (0<=j<=i) 중 최솟값으로 정할 수 있는데, 
    이렇게 되면 CHT를 위한 일차함수 꼴로 변경하였을 때
    j번쨰 first(기울기) * i번째 second(x) + dp[j-1](절편)으로 만드는 게 가능함

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

ll dp[50005]={},f1[50005]={},f2[50005]={};
pair <ll,ll> p[50005];
vector <pair<ll,ll>> v;
int cnt=0,n;
// f1이 기울기, f2가 절편

ld intersect(ll x, ll y){
    ld temp1=(f2[y]-f2[x]),temp2=(f1[x]-f1[y]);
    return (ld)(temp1/temp2);
}

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
    for(int i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);
    v.push_back(p[n-1]);
    for(int i=n-2; i>=0; i--){
        if(p[i].second>v.back().second){
            v.push_back(p[i]);
        }
    }
    reverse(v.begin(),v.end());
    f1[0]=v[0].second;
    f2[0]=0;
    dp[0]=v[0].first*v[0].second;
    int Hull_Points=1;
    for(int i=1; i<v.size(); i++){
        f1[Hull_Points]=v[i].second;
        f2[Hull_Points]=dp[i-1];
        while(true){
            if(cnt+1>=Hull_Points || intersect(Hull_Points-1,Hull_Points-2)<=intersect(Hull_Points-1,Hull_Points)){
                break;
            }
            f1[Hull_Points-1]=f1[Hull_Points];
            f2[Hull_Points-1]=f2[Hull_Points];
            Hull_Points--;
        }
        Hull_Points++;
        while(true){
            if(cnt+1>=Hull_Points || f2[cnt+1]-f2[cnt]>v[i].first*(f1[cnt]-f1[cnt+1])){
                break;
            }
            cnt++;
        }
        dp[i]=f1[cnt]*v[i].first+f2[cnt];
    }
    cout << dp[v.size()-1];

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
