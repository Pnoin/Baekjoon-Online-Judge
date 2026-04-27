#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,xp,xn,ypo,yne,visit[10005][10005]={};
vector <pair<int,int>> q1,q2,q3,q4;

int gcd(int a, int b){
	int c;
	while (b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int solve(vector <pair<int,int>> v){
    int total=0;
    memset(visit,0,sizeof(visit));
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        int temp=gcd(max(v[i].first,v[i].second),min(v[i].first,v[i].second));
        if(visit[v[i].first/temp][v[i].second/temp]==0){
            visit[v[i].first/temp][v[i].second/temp]=1;
            total++;
        }
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int xx,yy;
        cin >> xx >> yy;
        if(xx>0 && yy>0){
            q1.push_back({xx,yy});
        }
        else if(xx<0 && yy>0){
            q2.push_back({abs(xx),yy});
        }
        else if(xx<0 && yy<0){
            q3.push_back({abs(xx),abs(yy)});
        }
        else if(xx>0 && yy<0){
            q4.push_back({xx,abs(yy)});
        }
        else if(xx==0 && yy>0){
            ypo=1;
        }
        else if(xx==0 && yy<0){
            yne=1;
        }
        else if(xx>0 && yy==0){
            xp=1;
        }
        else if(xx<0 && yy==0){
            xn=1;
        }
    }
    ///cout << xn << '\n' << xp << '\n' << yne<< '\n' << ypo<< '\n' << solve(q1)<< '\n' << solve(q2)<< '\n' << solve(q3)<< '\n' << solve(q4)<< '\n';
    cout << xn+xp+yne+ypo+solve(q1)+solve(q2)+solve(q3)+solve(q4);
}