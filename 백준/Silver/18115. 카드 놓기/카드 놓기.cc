#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <deque>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int n;
deque <int> dq;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i]==1){
            dq.push_back(i+1);
        }
        else if(v[i]==2){
            int temp=dq.back();
            dq.pop_back();
			dq.push_back(i+1);
			dq.push_back(temp);
        }
        else if(v[i]==3){
            dq.push_front(i+1);
        }
    }
    reverse(dq.begin(),dq.end());
    for(int i=0; i<n; i++){
        cout << dq[i] << ' ';
    }
}