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

int n,m,x,c;
int temp=-1,ans[10005]={},presence[10005]={},v[300005]={};
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
	cin >> n >> c;
    x=sqrt(n);
    for(register int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> m;
    for(register int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        mos.push_back({i,{a-1,b-1}});
    }
    sort(mos.begin(),mos.end(),mos_sort);
    int start=mos[0].second.first, end=mos[0].second.second, k=(mos[0].second.second-mos[0].second.first+1)/2;
    for(register int i=start; i<=end; i++){
        presence[v[i]]++;
        if(presence[v[i]]>k){
            temp=v[i];
        }
    }
	ans[mos[0].first]=temp;
	for(register int i=1; i<m; i++){
        temp=-1;
        k=(mos[i].second.second-mos[i].second.first+1)/2;
		while(start<mos[i].second.first){
            presence[v[start]]--;
            start++;
        }
		while(start>mos[i].second.first){
            start--;
            presence[v[start]]++;
        }
		while(end<mos[i].second.second){
            end++;
            presence[v[end]]++;
        }
		while(end>mos[i].second.second){
            presence[v[end]]--;
            end--;
        }
        for(register int i=1; i<=c; i++){    //c<=10000, m<=10000     max = 1e8
            if(presence[i]>k){
                temp=i;
                break;
            }
        }
        ans[mos[i].first]=temp;
	}
	for(register int i=0; i<m; i++){
        if(ans[i]==-1){
            cout << "no" << '\n';
        }
        else{
            cout << "yes" << ' ' << ans[i] << '\n';
        }
    }
}