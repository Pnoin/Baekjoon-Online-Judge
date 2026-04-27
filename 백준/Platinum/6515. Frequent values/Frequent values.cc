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

int n,m,x,cnt[200005]={},mx=0,ans[200005]={},presence[200005]={};
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
    while(true){
        v.clear();
        mos.clear();
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        memset(presence,0,sizeof(presence));
        cin >> n;
        if(n==0){
            break;
        }
        cin >> m;
        x=sqrt(n);
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.push_back(num+100000);
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            mos.push_back({i,{a-1,b-1}});
        }
        sort(mos.begin(),mos.end(),mos_sort);
        int start=mos[0].second.first, end=mos[0].second.second;
        for(int i=start; i<=end; i++){
            cnt[presence[v[i]]]--;
            presence[v[i]]++;
            cnt[presence[v[i]]]++;
            if(presence[v[i]]>mx){
                mx=presence[v[i]];
            }
        }
        ans[mos[0].first]=mx;
        for(int i=1; i<m; i++){
            while(start<mos[i].second.first){
                cnt[presence[v[start]]]--;
                presence[v[start]]--;
                cnt[presence[v[start]]]++;
                if(cnt[mx]==0){
                    mx=presence[v[start]];
                }
                start++;
            }
            while(start>mos[i].second.first){
                start--;
                cnt[presence[v[start]]]--;
                presence[v[start]]++;
                cnt[presence[v[start]]]++;
                if(presence[v[start]]>mx){
                    mx=presence[v[start]];
                }
            }

            while(end<mos[i].second.second){
                end++;
                cnt[presence[v[end]]]--;
                presence[v[end]]++;
                cnt[presence[v[end]]]++;
                if(presence[v[end]]>mx){
                    mx=presence[v[end]];
                }
            }
            while(end>mos[i].second.second){
                cnt[presence[v[end]]]--;
                presence[v[end]]--;
                cnt[presence[v[end]]]++;
                if(cnt[mx]==0){
                    mx=presence[v[end]];
                }
                end--;
            }
            ans[mos[i].first]=mx;
        }
        for(int i=0; i<m; i++){
            cout << ans[i] << "\n";
        }
    }
}