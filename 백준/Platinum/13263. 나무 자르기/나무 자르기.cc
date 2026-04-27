/*
    <메모>
    CHT 공부 자료: https://koosaga.com/4 

    핵심:
    1. 나이브하게 점화식을 찾기 (주로 2차원 이상의 형태로 주어질 것임)
    2. 일차함수로 변환하기
    3. 최솟값이 존재하는 위치는 일차함수들을 모두 시각화하였을 때 그려지는 볼록 껍질임
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

ll n,a[100005]={},b[100005]={},dp[100005]={},f1[100005]={},f2[100005]={},cnt=0;

ld intersect(ll x, ll y){
    return (ld)(f2[y]-f2[x])/(f1[x]-f1[y]);
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
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    f1[0]=b[0];
    f2[0]=0;
    int Hull_Points=1;
    for(int i=1; i<n; i++){
        while(true){
            if(cnt+1>=Hull_Points || intersect(cnt,cnt+1)>a[i]){
                break;
            }
            cnt++;
        }
        dp[i]=f1[cnt]*a[i]+f2[cnt];
        f1[Hull_Points]=b[i];
        f2[Hull_Points]=dp[i];
        while(true){
            if(intersect(Hull_Points-1,Hull_Points-2)<=intersect(Hull_Points-1,Hull_Points) || Hull_Points<=1){
                break;
            }
            f1[Hull_Points-1]=f1[Hull_Points];
            f2[Hull_Points-1]=f2[Hull_Points];
            Hull_Points--;
        }
        Hull_Points++;
    }
    cout << dp[n-1];

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
