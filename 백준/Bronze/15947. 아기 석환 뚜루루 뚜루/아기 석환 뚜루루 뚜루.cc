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

string arr[14]={"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(arr[(n-1)%14]=="turu" || arr[(n-1)%14]=="tururu"){
        for(int i=0; i<n/14; i++){
            arr[(n-1)%14]+="ru";
        }
        if(arr[(n-1)%14].size()>=12){
            arr[(n-1)%14]="tu+ru*"+to_string((arr[(n-1)%14].size()-2)/2);
        }
    }
    cout << arr[(n-1)%14];
}