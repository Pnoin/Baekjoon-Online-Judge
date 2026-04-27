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

int n,k;
ll leftin=0,rightin=0,temp1,temp2;
vector <ll> a,Ltree,Rtree;

void Lupdate(int node, int start, int end, int idx){
    if(start>idx || end<idx){
        return;
    }
    if(start==end){
        Ltree[node]=1;
        return; 
    }
    Lupdate(node*2,start,(start+end)/2,idx);
    Lupdate(node*2+1,(start+end)/2+1,end,idx);
    Ltree[node]=Ltree[node*2]+Ltree[node*2+1];
}

ll Lquery(int node, int start, int end, int left, int right){
    if(start>right || end<left){
        return 0; 
    }
    if(start>=left && end<=right){
        return Ltree[node];
    }
    ll left_sum=Lquery(node*2,start,(start+end)/2,left,right);
    ll right_sum=Lquery(node*2+1,(start+end)/2+1,end,left,right);
    return left_sum+right_sum;
}

void Rupdate(int node, int start, int end, int idx){
    if(start>idx || end<idx){
        return;
    }
    if(start==end){
        Rtree[node]=1;
        return; 
    }
    Rupdate(node*2,start,(start+end)/2,idx);
    Rupdate(node*2+1,(start+end)/2+1,end,idx);
    Rtree[node]=Rtree[node*2]+Rtree[node*2+1];
}

ll Rquery(int node, int start, int end, int left, int right){
    if(start>right || end<left){
        return 0; 
    }
    if(start>=left && end<=right){
        return Rtree[node];
    }
    ll left_sum=Rquery(node*2,start,(start+end)/2,left,right);
    ll right_sum=Rquery(node*2+1,(start+end)/2+1,end,left,right);
    return left_sum+right_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int h=(int)ceil(log2(n+1));
    int tree_size=(1<<(h+1));
    a.resize(n);
    Ltree.resize(tree_size);
    Rtree.resize(tree_size);
    int revck=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
        if(a[i]==0 && i>=k){
            revck=1;
        }
    }
    if(revck){
        reverse(a.begin(),a.end());
        k=n-k+1;
    }
    int mn=1e9,idx=0;
    for(register int i=k; i<n; i++){
        if(a[i]<mn){
            mn=a[i];
            idx=i;
        }
    }
    for(register int i=0; i<k; i++){
        Lupdate(1,0,n-1,a[i]);
        leftin+=Lquery(1,0,n-1,0,a[i]-1);
    }
    for(register int i=k; i<n; i++){
        Rupdate(1,0,n-1,a[i]);
        rightin+=Rquery(1,0,n-1,a[i]+1,n-1);
    }    
    if(a[k-1]==0){
        if((leftin+rightin)%2){
            cout << "Minchan";
        }
        else{
            cout << "Junee";
        }
    }
    else{
        if((leftin+rightin)%2){
            cout << "Minchan";
        }
        else{
            if(mn>a[k-1]){
                cout << "Junee";
            }
            else{
                if((a[k-1]%2)==(mn%2)){
                    cout << "Junee";
                }
                else{
                    cout << "Minchan";
                }
            }
        }
    }
} 