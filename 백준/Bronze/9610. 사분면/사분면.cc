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

int n,arr[5]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if(x==0 || y==0){
            arr[4]++;
        }
        else if(x>0 && y>0){
            arr[0]++;
        }
        else if(x<0 && y>0){
            arr[1]++;
        }
        else if(x<0 && y<0){
            arr[2]++;
        }
        else if(x>0 && y<0){
            arr[3]++;
        }
    }
    cout << "Q1: " << arr[0] << '\n' << "Q2: " << arr[1] << '\n' << "Q3: " << arr[2] << '\n' << "Q4: " << arr[3] << '\n' << "AXIS: " << arr[4] << '\n'; 
}