#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n;
char arr[105][105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int r=0,c=0,temp=0;
    for(int i=0; i<n; i++){
        temp=0;
        for(int j=0; j<n; j++){
            if(arr[i][j]=='.'){
                temp++;
            }
            else{
                if(temp>=2){
                    r++;
                }
                temp=0;
            }
        }
        if(temp>=2){
            r++;
        }
    }
    for(int i=0; i<n; i++){
        temp=0;
        for(int j=0; j<n; j++){
            if(arr[j][i]=='.'){
                temp++;
            }
            else{
                if(temp>=2){
                    c++;
                }
                temp=0;
            }
        }
        if(temp>=2){
            c++;
        }
    }
    cout << r << ' ' << c;
}