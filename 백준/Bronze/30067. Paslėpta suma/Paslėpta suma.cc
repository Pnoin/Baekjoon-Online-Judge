#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int arr[10]={},sum=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(int i=0; i<10; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    for(int i=0; i<10; i++){
        if(sum-arr[i]==arr[i]){
            cout << arr[i];
            return 0;
        }
    }
}