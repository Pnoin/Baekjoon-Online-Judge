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

int n,k; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int num; 
        cin >> num;
        if((num*100)/n<=4){
            cout << "1 ";
        }
        else if((num*100)/n<=11){
            cout << "2 ";
        }
        else if((num*100)/n<=23){
            cout << "3 ";
        }
        else if((num*100)/n<=40){
            cout << "4 ";
        }
        else if((num*100)/n<=60){
            cout << "5 ";
        }
        else if((num*100)/n<=77){
            cout << "6 ";
        }
        else if((num*100)/n<=89){
            cout << "7 ";
        }
        else if((num*100)/n<=96){
            cout << "8 ";
        }
        else{
            cout << "9 ";
        }
    }
   
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}