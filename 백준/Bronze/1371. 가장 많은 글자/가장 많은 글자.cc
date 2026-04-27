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

string s;
int arr[30]={},ans=0;
char c[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> s){
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++){
        ans=max(ans,arr[i]);
    }
    for(int i=0; i<26; i++){
        if(arr[i]==ans){
            cout << c[i];
        }
    }
}