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
typedef long long int ll;
using namespace std;
typedef complex<double> cpx;
typedef vector<cpx> vec;
const double pi = acos(-1);

int n, arr[1005]={}, temp=0, temp2=0, cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        temp^=arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=arr[i]; j++){
            temp2=arr[i]-j;
            temp2^=arr[i];
            temp2^=temp;
            if(temp2==0){
                cnt++;
            }
        }
    }
    cout << cnt;
}