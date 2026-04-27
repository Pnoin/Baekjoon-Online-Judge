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

int b,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> b >> n;
        if(b==0 && n==0){
            break;
        }
        int a=1;
        while(true){
            if((int)pow(a,n)==b){
                break;
            }
            if((int)pow(a,n)>b){
                if(abs((int)pow(a-1,n)-b)<abs((int)pow(a,n)-b)){
                    a--;
                    break;
                }
                else{
                    break;
                }
            }
            a++;
        }
        cout << a << '\n';
    }
}