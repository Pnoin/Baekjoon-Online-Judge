/*
회전하는 캘리퍼스를 풀기 위한 앞걸음

참고 자료:
https://david0506.tistory.com/62                 볼록껍질
https://stonejjun.tistory.com/40                 그라함 알고리즘
https://snowfleur.tistory.com/98                 CCW 알고리즘
https://blog.naver.com/mindo1103/90103361104     벡터의 외적
*/

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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n;
pair <ll,ll> arr[100005], Convex_Hull[100005];

/// ccw < 0 --> 반시계
/// ccw > 0 --> 시계
/// ccw = 0 --> 일직선

ll ccw(pair <ll,ll> a, pair <ll,ll> b, pair <ll,ll> c){
    if((a.first-b.first)*(c.second-b.second)-(a.second-b.second)*(c.first-b.first)<0){
        return 1;
    }
    else if((a.first-b.first)*(c.second-b.second)-(a.second-b.second)*(c.first-b.first)==0){
        return 0;
    }
    else{
        return -1; 
    }
}

ll distance(pair <ll,ll> a, pair <ll,ll> b){
    return (b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
}

bool cmp(pair <ll,ll> a, pair <ll,ll> b){
    // X좌표가 작은 거부터
    if(a.first!=b.first){
        return a.first<b.first;
    }
    // X좌표가 같으면 Y좌표가 작은 거부터
    return a.second<b.second;
}

bool cmp2(pair <ll,ll> a, pair <ll,ll> b){
    // 세 점의 ccw값이 0이라는 건 세 점들이 모두 일직선상에 존재한다는 것. 
    // 점들이 일직선 상에 존재하면 가까운 점들을 우선적으로 처리. 
    if(ccw(arr[0],a,b)==0){
        return distance(arr[0],a)<distance(arr[0],b);
    }
    return ccw(arr[0],a,b)>0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+n,cmp);
    sort(arr+1,arr+n,cmp2);
    ll Hull_Points=2; 
    Convex_Hull[0]=arr[0];
    Convex_Hull[1]=arr[1];
    for(int i=2; i<n; i++){
        while(Hull_Points>=2 && ccw(Convex_Hull[Hull_Points-2],Convex_Hull[Hull_Points-1],arr[i])<=0){
            Hull_Points--;
        }
        Convex_Hull[Hull_Points]=arr[i];
        Hull_Points++;
    }
    cout << Hull_Points;
}