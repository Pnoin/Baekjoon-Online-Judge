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

int arr[3]={};
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<3; i++){
        cin >> arr[i];
    }
    cin >> s;
	sort(arr,arr+3);
	for(int i=0; i<3; i++){
        cout << arr[s[i]-65] << ' ';
    }
}