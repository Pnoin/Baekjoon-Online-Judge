#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#include <tuple>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
typedef long long int ll;
using namespace std;

int x[1005]={},n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x[0] >> n;
    for(int i=1; i<=n; i++){
        if(x[i-1]%2==0){
            x[i]=floor((x[i-1]/2)^6);
        }
        else if(x[i-1]%2==1){
            x[i]=(2*x[i-1])^6;
        }
    }
    cout << x[n];
}