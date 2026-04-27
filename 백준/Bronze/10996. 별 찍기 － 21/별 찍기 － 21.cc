#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    if(n==1){
        cout << '*';
        return 0; 
    }
    for(int i=0; i<n*2; i++){
        for(int j=0; j<n; j++){
            if(i%2==0){
                if(j%2==0){
                    cout << '*';
                }
                else{
                    cout << ' ';
                }
            }
            else{
                if(j%2==0){
                    cout << ' ';
                }
                else{
                    cout << '*';
                }
            }
        }
        cout << '\n';
    }
}