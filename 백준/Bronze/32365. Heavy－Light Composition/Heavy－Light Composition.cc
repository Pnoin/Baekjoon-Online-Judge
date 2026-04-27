#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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
const ll INF = 1e18;

int n,x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	/*
    clock_t start,finish;
    double duration;
    start=clock();
	*/

    cin >> n >> x;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int arr[26]={};
        memset(arr,0,sizeof(arr));
        for(int j=0; j<s.size(); j++){
            arr[s[j]-'a']++;
        }
        for(int j=0; j<26; j++){
            if(arr[j]>1){
                arr[j]=0;
            }
        }
        char ans='T';
        for(int j=0; j<s.size()-1; j++){
            if(arr[s[j]-'a']==arr[s[j+1]-'a']){
                ans='F';
                break;
            }
        }
        cout << ans << '\n';
    }

	/*
	finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}