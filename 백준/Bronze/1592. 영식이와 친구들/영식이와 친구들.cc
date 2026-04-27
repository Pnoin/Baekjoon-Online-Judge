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

int a,b,c,arr[55]={},total=0,idx=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    while(true){
        if(arr[idx]==b){
            break;
        }
        if(arr[idx]%2){ 
            if(idx+c>a){ 
                idx+=c;
                idx-=a;
            } 
            else{
                idx+=c;
            }
        } 
        else{ 
            if(idx-c<1){
                idx+=a;
                idx-=c;
            }
            else{
                idx-=c;
            }
        }
        arr[idx]++; 
        total++; 
    }
    cout << total-1; 
}