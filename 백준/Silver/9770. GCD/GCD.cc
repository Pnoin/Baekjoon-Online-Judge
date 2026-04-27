#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

string s;
vector <int> v;

int gcd(int x, int y){
    int z;
    while(true){
        if(y==0){
            return x;
        }
        z=x%y;
        x=y;
        y=z;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    while(getline(cin, s)){
        string temp;
        stringstream stream(s);
        while(stream >> temp){
            v.push_back(stoi(temp));
        }
    }
    int ans=0;
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            ans=max(ans,gcd(max(v[i],v[j]),min(v[i],v[j])));
        }
    }
    cout << ans;
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}