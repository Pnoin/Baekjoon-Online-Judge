#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <cstring>

#include <vector>

#include <complex>

#include <queue>

#include <cstdio>

#include <set>

#pragma GCC optimize("O3")

#pragma GCC optimize("Ofast")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

typedef long long int ll;

using namespace std;

int n,m, arr[200005]={},cnt=0;

ll total=0; 

priority_queue<int,vector<int>,less<int>> pq;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){

        cin >> arr[i];

        total+=arr[i];

        pq.push(arr[i]);

        if(total>=m){

            total-=(pq.top()*2);

            cnt++;

            pq.pop();

        }

    }

    cout << cnt;

}