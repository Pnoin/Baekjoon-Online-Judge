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

int n,t;
pair <pair <ll,ll>,ll> arr[2005];

/// ccw < 0 --> 반시계
/// ccw > 0 --> 시계
/// ccw = 0 --> 일직선

ll ccw(pair <pair <ll,ll>,ll> a, pair <pair <ll,ll>,ll> b, pair <pair <ll,ll>,ll> c){
    if((a.first.first-b.first.first)*(c.first.second-b.first.second)-(a.first.second-b.first.second)*(c.first.first-b.first.first)<0){
        return 1;
    }
    else if((a.first.first-b.first.first)*(c.first.second-b.first.second)-(a.first.second-b.first.second)*(c.first.first-b.first.first)==0){
        return 0;
    }
    else{
        return -1; 
    }
}

ll distance(pair <pair <ll,ll>,ll> a, pair <pair <ll,ll>,ll> b){
    return (b.first.first-a.first.first)*(b.first.first-a.first.first)+(b.first.second-a.first.second)*(b.first.second-a.first.second);
}

ld Euclidean_Distance(pair <pair <ll,ll>,ll> a, pair <pair <ll,ll>,ll> b){
    return sqrt(distance(a,b));
}

bool cmp(pair <pair <ll,ll>,ll> a, pair <pair <ll,ll>,ll> b){
    // X좌표가 작은 거부터
    if(a.first.first!=b.first.first){
        return a.first.first<b.first.first;
    }
    // X좌표가 같으면 Y좌표가 작은 거부터
    return a.first.second<b.first.second;
} 

bool cmp2(pair <pair <ll,ll>,ll> a, pair <pair <ll,ll>,ll> b){
    // 세 점의 ccw값이 0이라는 건 세 점들이 모두 일직선상에 존재한다는 것. 
    // 점들이 일직선 상에 존재하면 가까운 점들부터 우선적으로 처리
    if(ccw(arr[0],a,b)==0){
        return distance(arr[0],a)<distance(arr[0],b);
    }
    return ccw(arr[0],a,b)>0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i].first.first >> arr[i].first.second;
            arr[i].second=i;
        }
        sort(arr,arr+n,cmp);
        sort(arr+1,arr+n,cmp2);
        int idx=n-1;
        while(ccw(arr[0],arr[idx-1],arr[idx])==0){
            idx--;
        }
        for(int i=0; i<idx; i++){
            cout << arr[i].second << ' ';
        }
        for(int i=n-1; i>=idx; i--){
            cout << arr[i].second << ' ';
        }
        cout << '\n';
    }
}