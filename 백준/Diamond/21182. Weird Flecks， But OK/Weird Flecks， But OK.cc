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
const double PI = acos(-1); 

int n;
ld a,b,c;
pair <ld,ld> points1[5005], points2[5005], points3[5005];

/// ccw < 0 --> 반시계
/// ccw > 0 --> 시계
/// ccw = 0 --> 일직선

ld ccw(pair <ld,ld> a, pair <ld,ld> b, pair <ld,ld> c){
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

ld distance(pair <ld,ld> a, pair <ld,ld> b){
    return (b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
}

bool cmp(pair <ld,ld> a, pair <ld,ld> b){
    // X좌표가 작은 거부터
    if(a.first!=b.first){
        return a.first<b.first;
    }
    // X좌표가 같으면 Y좌표가 작은 거부터
    return a.second<b.second;
}

bool cmp2(pair <ld,ld> a, pair <ld,ld> b){
    // 세 점의 ccw값이 0이라는 건 세 점들이 모두 일직선상에 존재한다는 것. 
    // 점들이 일직선 상에 존재하면 가까운 점들을 우선적으로 처리. 
    if(ccw(points1[0],a,b)==0){
        return distance(points1[0],a)<distance(points1[0],b);
    }
    return ccw(points1[0],a,b)>0;
}

bool cmp3(pair <ld,ld> a, pair <ld,ld> b){
    // 세 점의 ccw값이 0이라는 건 세 점들이 모두 일직선상에 존재한다는 것. 
    // 점들이 일직선 상에 존재하면 가까운 점들을 우선적으로 처리. 
    if(ccw(points2[0],a,b)==0){
        return distance(points2[0],a)<distance(points2[0],b);
    }
    return ccw(points2[0],a,b)>0;
}
bool cmp4(pair <ld,ld> a, pair <ld,ld> b){
    // 세 점의 ccw값이 0이라는 건 세 점들이 모두 일직선상에 존재한다는 것. 
    // 점들이 일직선 상에 존재하면 가까운 점들을 우선적으로 처리. 
    if(ccw(points3[0],a,b)==0){
        return distance(points3[0],a)<distance(points3[0],b);
    }
    return ccw(points3[0],a,b)>0;
}

ld solve(pair <ld,ld> arr[], int ck){
    pair <ld,ld> Convex_Hull[5005];
    sort(arr,arr+n,cmp);
    if(ck==1){
        sort(arr+1,arr+n,cmp2);
    }
    else if(ck==2){
        sort(arr+1,arr+n,cmp3);
    }
    else{
        sort(arr+1,arr+n,cmp4);
    }
    int Hull_Points=2; 
    Convex_Hull[0]=arr[0];
    Convex_Hull[1]=arr[1];
    for(int i=2; i<n; i++){
        while(Hull_Points>=2 && ccw(Convex_Hull[Hull_Points-2],Convex_Hull[Hull_Points-1],arr[i])<=0){
            Hull_Points--;
        }
        Convex_Hull[Hull_Points]=arr[i];
        Hull_Points++;
    }
    ld cx=0,cy=0;
    for(int i=0; i<Hull_Points; i++){
        cx+=Convex_Hull[i].first;
        cy+=Convex_Hull[i].second;
    }
    cx/=Hull_Points;
    cy/=Hull_Points;
    ld rat=0.1; 
    for(int i=0; i<50000; i++){
        ld farthest_distance=0;
        int idx=0;
        for(int j=0; j<Hull_Points; j++){
            ld temp_distance=sqrtl(distance({cx,cy},Convex_Hull[j]));
            if(farthest_distance<temp_distance){
                farthest_distance=temp_distance;
                idx=j;
            }
        }
        cx+=(Convex_Hull[idx].first-cx)*rat;
        cy+=(Convex_Hull[idx].second-cy)*rat;
        rat*=0.999;
    }
    ld ans_dis=0;
    for(int i=0; i<n; i++){
        ans_dis=max(ans_dis,sqrtl(distance({cx,cy},arr[i])));
    }
    return ans_dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        points1[i]={a,b};
        points2[i]={b,c};
        points3[i]={c,a};
    }
    cout << 2*min(min(solve(points1,1),solve(points2,2)),solve(points3,3));
}