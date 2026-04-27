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

int t,n,visit[100005]={},arr[100005]={},cycle[100005],cnt=0;

void dfs(int cur){
    visit[cur]=1;
    if(visit[arr[cur]]==0){
        dfs(arr[cur]);
    }
    else{
        if(cycle[arr[cur]]==0){
			for(int i=arr[cur]; i!=cur; i=arr[i]){
				cnt++;
			}
			cnt++;
		} 
    }
    cycle[cur]=1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        memset(cycle,0,sizeof(cycle));
        cnt=0;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }
        for(int i=1; i<=n; i++){
            if(visit[i]==0){
                dfs(i);
            }
        }
        cout << n-cnt << '\n';
    }
} 