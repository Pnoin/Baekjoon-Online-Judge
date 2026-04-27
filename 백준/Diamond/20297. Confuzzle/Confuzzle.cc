/*
    <메모>
    2024.07.07 
    https://howtoliveworldnice.tistory.com/544
    https://www.youtube.com/watch?v=7v65lpxSdIY&ab_channel=IOIKOREA
    센트로이드 참고 영상 및 블로그


    FFT 처음 공부했을 때랑 마찬가지로, 원리 이해 난이도에 비해 응용 난이도가 상당히 높은 거 같음
    얘는 무조건 복습 다시 해야함
    앞으로 몇 일간 날잡고 센트로이드 문제를 몇 개 시도해봐야한다

    센트로이드 분할의 기본적인 3개의 함수들 --> 1. 서브트리의 크기 구하기, 2. 센트로이드 구하기, 3. 그걸 바탕으로 문제 풀기
    어느 정도 원리를 이해하면 1번 2번까지는 쉽게 구현이 되는 듯 함 (템플릿이 정해져있는 느낌)
    근데 문제는 저걸 막상 써먹으려하면 난해해짐
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,a[100005],Size[100005]={};
bool visit[100005]={};
vector <int> newtree[100005],adj[100005];
pair <int,int> ans[100005]={};

int finding_size(int cur, int prv){
    Size[cur]=1;
    for(int i=0; i<adj[cur].size(); i++){
        if(adj[cur][i]!=prv && !visit[adj[cur][i]]){
            Size[cur]+=finding_size(adj[cur][i],cur);
        }
    }
    return Size[cur];
}

int Centroid(int cur, int prv, int tempsize){
    for(int i=0; i<adj[cur].size(); i++){
        if(adj[cur][i]!=prv && !visit[adj[cur][i]] && Size[adj[cur][i]]*2>tempsize){
            return Centroid(adj[cur][i],cur,tempsize);
        }
    }
    return cur;
}

/*
    처음에 임시로 제출했던 코드는 센트로이드 분할을 잘못 활용했었음
    센트로이드 분할로 첫 센트로이드부터 시작하여 서브트리로 쪼개어 나가는 과정에서 기존의 정점들을 새로운 방식으로 재정렬 시킨 후, 효율적인 트리 형식으로 재구성하여 다시 만들어 활용했지만 dfs 파트를 잘못 생각함. 오히려 센트로이드로 새로운 트리를 만드는 게 무의미한 코드를 짜버림

    결국 코드를 아예 뜯어고쳐야되었음
    
*/
/*
void subtree(int cur){ //새로운 트리 생성
    int cur_centroid=Centroid(cur,-1,finding_size(cur,-1));
    visit[cur_centroid]=true;
    if(!startidxck){
        startidx=cur_centroid;
        startidxck=true;
    }
    for(int i=0; i<adj[cur_centroid].size(); i++){
        if(!visit[adj[cur_centroid][i]]){
            newtree[cur_centroid].push_back(adj[cur_centroid][i]);
            subtree(adj[cur_centroid][i]);
        }
    }
}
*/
void dfs(map <int,int> &m, int cur, int prv, int depth){
    int temp=a[cur];
    if(m.find(temp)==m.end()){
        m[temp]=depth;
    }
    else{
        m[temp]=min(depth,m[temp]);
    }
    for(int i=0; i<adj[cur].size(); i++){
        if(adj[cur][i]!=prv && !visit[adj[cur][i]]){
            dfs(m,adj[cur][i],cur,depth+1);
        }
    }
}

int solve(int cur){ 
    map <int,int> m;  // <정점 번호, 거리>
    int cur_centroid=Centroid(cur,-1,finding_size(cur,-1));
    visit[cur_centroid]=true;
    m[a[cur_centroid]]=0;
    int finans=1e9;
    for(int i=0; i<adj[cur_centroid].size(); i++){
        if(!visit[adj[cur_centroid][i]]){
            map <int,int> tempdepth;
            dfs(tempdepth,adj[cur_centroid][i],cur_centroid,1);
            for(auto [x,y]:tempdepth){
                if(m.find(x)!=m.end()){
                    finans=min(y+m[x],finans);
                }
            }
            for(auto [x,y]:tempdepth){
                if(m.find(x)==m.end()){
                    m[x]=y;
                }
                else{
                    m[x]=min(m[x],y);
                }
            }
        }
    }
    for(int i=0; i<adj[cur_centroid].size(); i++){
        if(!visit[adj[cur_centroid][i]]){
            finans=min(finans,solve(adj[cur_centroid][i]));   
        }
    }
    return finans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    cout << solve(0);

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
