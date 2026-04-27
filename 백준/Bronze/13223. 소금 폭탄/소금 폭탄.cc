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
#include <regex>
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

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
    
    cin >> a >> b;
    int h1=(a[0]-'0')*10+(a[1]-'0'),m1=(a[3]-'0')*10+(a[4]-'0'),s1=(a[6]-'0')*10+(a[7]-'0'),h2=(b[0]-'0')*10+(b[1]-'0'),m2=(b[3]-'0')*10+(b[4]-'0'),s2=(b[6]-'0')*10+(b[7]-'0');
    int cur=h1*3600+m1*60+s1,tar=h2*3600+m2*60+s2;
    int diff=tar-cur;
    if(diff<=0){
        diff+=24*3600;
    }
    int h=diff/3600;
    diff%=3600;
    int m=diff/60;
    int s=diff%60;
    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << ":";
    cout << setw(2) << setfill('0') << s;


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

