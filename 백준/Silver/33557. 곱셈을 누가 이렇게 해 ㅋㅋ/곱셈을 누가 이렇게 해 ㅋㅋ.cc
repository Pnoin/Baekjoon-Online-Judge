#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int t;
string a,b;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        ll realval=(ll)stoi(a)*(ll)stoi(b);
        if(a.size()<b.size()){
            string temp=a;
            a=b;
            b=temp;
        }
        if(b.size()<a.size()){
            reverse(b.begin(),b.end());
            while(true){
                if(a.size()==b.size()){
                    break;
                }
                b.push_back('1');
            }
            reverse(b.begin(),b.end());
        }
        string wrongval="";
        for(int j=0; j<a.size(); j++){
            int temp2=(a[j]-48)*(b[j]-48);
            wrongval+=to_string(temp2);
        }
        if(wrongval==to_string(realval)){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}