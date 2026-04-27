#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

int n,total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        string s1,s2;
        cin >> s1;
        s2=s1;
        reverse(s1.begin(),s1.end());
        int total=stoi(s1)+stoi(s2);
        string ans=to_string(total),p="YES";
        for(int j=0; j<ans.size()/2; j++){
            if(ans[j]!=ans[ans.size()-j-1]){
                p="NO";
                break;
            }
        }
        cout << p << '\n';
    }
}