#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <time.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,cnt=1;
vector <string> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        cin.ignore();
        v.clear();
        for(int i=0; i<n; i++){
            string s;
            getline(cin,s);
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        cout << cnt << '\n';
        for(int i=0; i<n; i++){
            cout << v[i] << '\n';
        }
        cnt++;
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}