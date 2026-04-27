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
const long double PI = acos(-1); 

int n,Hull_Points=2;
pair <ll,ll> Convex_Hull[100005];
vector <pair <ll,ll>> arr;

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

//https://stonejjun.tistory.com/42 아이디어 참고는 이 블로그
//https://velog.io/@jihwan0319/%ED%9A%8C%EC%A0%84%ED%95%98%EB%8A%94-%EC%BA%98%EB%A6%AC%ED%8D%BC%EC%8A%A4-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98  구현 참고는 이 블로그
ll calipers(){
	ll ans=0;
	int left=0,right=0;
	for(int i=0; i<Hull_Points; i++){
		if(Convex_Hull[i].first<Convex_Hull[left].first){
			left=i;
        }
		if(Convex_Hull[i].first>Convex_Hull[right].first){
			right=i;
        }
	}
	ans=distance(Convex_Hull[left],Convex_Hull[right]);
	for(int i=0; i<Hull_Points; i++){
		pair <ll,ll> previous,next;
		previous.first=Convex_Hull[(left+1)%Hull_Points].first-Convex_Hull[left].first;
		previous.second=Convex_Hull[(left+1)%Hull_Points].second-Convex_Hull[left].second;
		next.first=Convex_Hull[right].first-Convex_Hull[(right+1)%Hull_Points].first;
		next.second=Convex_Hull[right].second-Convex_Hull[(right+1)%Hull_Points].second;
		if(ccw({0,0},previous,next)>0){
			left++;
            left%=Hull_Points;
        }
		else{
            right++;
            right%=Hull_Points;
        }
		ans=max(ans,distance(Convex_Hull[left],Convex_Hull[right]));
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        ll xx,yy;
        cin >> xx >> yy;
        arr.push_back({xx,yy});
    }
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    sort(arr.begin(),arr.end(),cmp);
    sort(arr.begin()+1,arr.end(),cmp2);
    Convex_Hull[0]=arr[0];
    Convex_Hull[1]=arr[1];
    for(int i=2; i<n; i++){
        while(Hull_Points>=2 && ccw(Convex_Hull[Hull_Points-2],Convex_Hull[Hull_Points-1],arr[i])<=0){
            Hull_Points--;
        }
        Convex_Hull[Hull_Points]=arr[i];
        Hull_Points++;
    }
    cout << calipers();
}