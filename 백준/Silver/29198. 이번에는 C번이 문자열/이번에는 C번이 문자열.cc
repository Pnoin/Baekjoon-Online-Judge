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

int n,m,k;
vector <char> v;
vector <string> temp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector <char> temp2;
    for(int i=0; i<n; i++){
        temp2.clear();
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            temp2.push_back(c);
        }
        sort(temp2.begin(), temp2.end());
        string s;
        for(int j=0; j<temp2.size(); j++){
            s.push_back(temp2[j]);
        }
        temp.push_back(s);
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i<k; i++){
        for(int j=0; j<m; j++){
            v.push_back(temp[i][j]);
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
}