#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <iomanip>
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
const ld PI=acos(-1); 
const ll INF=1e18;

int n,arr[26]={},cnt=0;
string s,a="abcdefghijklmnopqrstuvwxyz";

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
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin,s);
        cnt=0;
        a="abcdefghijklmnopqrstuvwxyz";
        memset(arr,0,sizeof(arr));
        for(int j=0; j<s.size(); j++){
            if(s[j]>='A' && s[j]<='Z'){
                if(arr[s[j]-'A']==0){
                    cnt++;
                }
                arr[s[j]-'A']++;
            }
            else if(s[j]>='a' && s[j]<='z'){
                if(arr[s[j]-'a']==0){
                    cnt++;
                }
                arr[s[j]-'a']++;
            }
        }
        if(cnt==26){
            cout << "pangram" << '\n';
        }
        else{
            cout << "missing ";
            for(int j=0; j<26; j++){
                if(arr[j]==0){
                    cout << a[j];
                }
            }
            cout << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   