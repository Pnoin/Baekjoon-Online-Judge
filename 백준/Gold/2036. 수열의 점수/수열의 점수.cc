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

int n;
ll total=0;
vector <ll> neg,zero,pos;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num<0){
            neg.push_back(num);
        }
        else if(num==0){
            zero.push_back(num);
        }
        else{
            pos.push_back(num);
        }
    }
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    reverse(pos.begin(),pos.end());
    if(neg.size()%2){
        if(zero.size()==0){
            total+=neg[neg.size()-1];
        }
        neg.pop_back();
    }
    for(int i=0; i<neg.size(); i+=2){
        total+=(neg[i]*neg[i+1]);
    }
    if(pos.size()%2){
        total+=pos[pos.size()-1];
        pos.pop_back();
    }
    for(int i=0; i<pos.size(); i+=2){
        if(pos[i]==1 || pos[i+1]==1){
            total+=(pos[i]+pos[i+1]);
        }
        else{
            total+=(pos[i]*pos[i+1]);
        }
    }
    cout << total;
} 