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

int n,total_questions=100,q1=35,q2=25,q3=40;
double pass_total_pct=55.0,pass_part_pct=30.0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n;
    for(int i=0; i<n; i++){
        string id;
        int s1,s2,s3;
        cin >> id >> s1 >> s2 >> s3;
        int sum=s1+s2+s3;
        double pct_total=sum*100.0/total_questions,pct1=s1*100.0/q1,pct2=s2*100.0/q2,pct3=s3*100.0/q3;
        bool pass=true;
        if(pct_total+1e-9<pass_total_pct || pct1+1e-9<pass_part_pct || pct2+1e-9<pass_part_pct || pct3+1e-9<pass_part_pct){
            pass=false;
        }
        cout << id << ' ' << sum << ' ' << (pass?"PASS":"FAIL") << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   