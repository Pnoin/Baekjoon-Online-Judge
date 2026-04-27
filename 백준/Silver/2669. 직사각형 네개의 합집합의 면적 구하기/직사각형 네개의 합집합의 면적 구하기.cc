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

int arr[105][105]={},total=0,a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<4; i++){
		cin >> a >> b >> c >> d;
		for(int j=b; j<d; j++){
			for(int k=a; k<c; k++){
				if(arr[j][k]==0){
                    arr[j][k]=1;
					total++;
				}
			}
		}
	}
    cout << total;
}