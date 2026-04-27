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
int temp=0,ans[100005]={},presence[100005]={},v[100005]={};
vector <int> pre;
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
    for(register int i=0; i<n; i++){
        cin >> v[i];
        pre.push_back(v[i]);
    }
    sort(pre.begin(),pre.end());
    pre.erase(unique(pre.begin(), pre.end()), pre.end());
    for(register int i=0; i<n; i++){
        v[i]=lower_bound(pre.begin(),pre.end(),v[i])-pre.begin();
    }
    for(register int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        mos.push_back({i,{a-1,b-1}});
    }
    sort(mos.begin(),mos.end(),mos_sort);
    int start=mos[0].second.first, end=mos[0].second.second;
    for(register int i=start; i<=end; i++){
        presence[v[i]]++;
        if(presence[v[i]]==3){
            temp++;
        }
    }
	ans[mos[0].first]=temp;
	for(register int i=1; i<m; i++){
		while(start<mos[i].second.first){
            if(presence[v[start]]==3){
                temp--;
            }
            presence[v[start]]--;
            start++;
        }
		while(start>mos[i].second.first){
            start--;
            presence[v[start]]++;
            if(presence[v[start]]==3){
                temp++;
            }
        }
		while(end<mos[i].second.second){
            end++;
            presence[v[end]]++;
            if(presence[v[end]]==3){
                temp++;
            }
        }
		while(end>mos[i].second.second){
            if(presence[v[end]]==3){
                temp--;
            }
            presence[v[end]]--;
            end--;
        }
		ans[mos[i].first]=temp;
	}
	for(register int i=0; i<m; i++){
        cout << ans[i] << '\n';
    }
}