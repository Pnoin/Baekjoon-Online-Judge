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
int temp=0,ans[100005]={};
int presence[1000005]={};
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
	cin >> n;
    x=sqrt(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        mos.push_back({i,{a-1,b-1}});
    }
    sort(mos.begin(),mos.end(),mos_sort);
    int start=mos[0].second.first, end=mos[0].second.second;
    for(int i=start; i<=end; i++){
        if(presence[v[i]]==0){
            temp++;
        }
        presence[v[i]]++;
    }
	ans[mos[0].first]=temp;
	for(int i=1; i<m; i++){
		while(start<mos[i].second.first){
            presence[v[start]]--;
            if(presence[v[start]]==0){
                temp--;
            }
            start++;
        }
		while(start>mos[i].second.first){
            start--;
            if(presence[v[start]]==0){
                temp++;
            }
            presence[v[start]]++;
        }
		while(end<mos[i].second.second){
            end++;
            if(presence[v[end]]==0){
                temp++;
            }
            presence[v[end]]++;
        }
		while(end>mos[i].second.second){
            presence[v[end]]--;
            if(presence[v[end]]==0){
                temp--;
            }
            end--;
        }
		ans[mos[i].first]=temp;
	}
	for(int i=0; i<m; i++){
        cout << ans[i] << "\n";
    }
}