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
ld x[35]={},y[35]={},z[35]={};
/*
pair <ld,ld> arr[305], Convex_Hull[305];

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
*/

ld distance(ld x1, ld x2, ld y1, ld y2, ld z1, ld z2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1);
}
/*
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
    if(ccw(arr[0],a,b)==0){
        return distance(arr[0],a)<distance(arr[0],b);
    }
    return ccw(arr[0],a,b)>0;
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        /*
        for(int i=0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr,arr+n,cmp);
        sort(arr+1,arr+n,cmp2);
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
        */
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i] >> z[i];
        }
        ld cx=0,cy=0,cz=0;
        for(int i=0; i<n; i++){
            cx+=x[i];
            cy+=y[i];
            cz+=z[i];
        }
        cx/=n;
        cy/=n;
        cz/=n;
        ld rat=0.1; 
        for(int i=0; i<50000; i++){
            ld farthest_distance=0;
            int idx=0;
            for(int j=0; j<n; j++){
                ld temp_distance=sqrtl(distance(cx,x[j],cy,y[j],cz,z[j]));
                if(farthest_distance<temp_distance){
                    farthest_distance=temp_distance;
                    idx=j;
                }
            }
            cx+=(x[idx]-cx)*rat;
            cy+=(y[idx]-cy)*rat;
            cz+=(z[idx]-cz)*rat;
            rat*=0.999;
        }
        ld ans_dis=0;
        for(int i=0; i<n; i++){
            ans_dis=max(ans_dis,sqrtl(distance(cx,x[i],cy,y[i],cz,z[i])));
        }
        cout << fixed;
        cout.precision(5);
        cout << ans_dis << '\n';
    }
}