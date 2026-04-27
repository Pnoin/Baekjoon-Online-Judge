#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n,m,x;
ll temp=0,ans[100005]={},presence[1000005]={};
vector <int> v;
vector <pair<int,pair<int,int>>> mos;

bool mos_sort(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.second.first/x != b.second.first/x){
        return a.second.first/x < b.second.first/x;
    }
	return a.second.second/x < b.second.second/x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m;
    x=sqrt(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        mos.push_back({i,{a-1,b-1}});
    }
    sort(mos.begin(),mos.end(),mos_sort);
    int start=mos[0].second.first, end=mos[0].second.second;
    for(int i=start; i<=end; i++){
        temp-=presence[v[i]]*presence[v[i]]*v[i];
        presence[v[i]]++;
        temp+=presence[v[i]]*presence[v[i]]*v[i];
    }
	ans[mos[0].first]=temp;
	for(int i=1; i<m; i++){
		while(start<mos[i].second.first){ 
            temp-=presence[v[start]]*presence[v[start]]*v[start];
            presence[v[start]]--;
            temp+=presence[v[start]]*presence[v[start]]*v[start];
            start++;
        }
		while(start>mos[i].second.first){ /// if문으로 나눌 필요가 없었음
            start--;
            temp-=presence[v[start]]*presence[v[start]]*v[start];
            presence[v[start]]++;
            temp+=presence[v[start]]*presence[v[start]]*v[start];
        }
		while(end<mos[i].second.second){
            end++;
            temp-=presence[v[end]]*presence[v[end]]*v[end];
            presence[v[end]]++;
            temp+=presence[v[end]]*presence[v[end]]*v[end];
        }
		while(end>mos[i].second.second){
            temp-=presence[v[end]]*presence[v[end]]*v[end];
            presence[v[end]]--;
            temp+=presence[v[end]]*presence[v[end]]*v[end];
            end--;
        }
		ans[mos[i].first]=temp;
	}
	for(int i=0; i<m; i++){
        cout << ans[i] << '\n';
    }
}