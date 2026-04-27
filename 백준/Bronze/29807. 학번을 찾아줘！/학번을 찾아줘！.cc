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

int t,score_kor=0,score_math=0,score_eng=0,score_tam=0,score_lang=0,val1,val2,val3; 

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
    if(t>=1){
        cin >> score_kor; 
    }
    if(t>=2){
        cin >> score_math; 
    }
    if(t>=3){
        cin >> score_eng; 
    }
    if(t>=4){
        cin >> score_tam; 
    }
    if(t>=5){
        cin >> score_lang; 
    }
    if(score_kor>score_eng){
        val1=(score_kor-score_eng)*508; 
    }
    else{
        val1=(score_eng-score_kor)*108; 
    }

    if(score_math>score_tam){
        val2=(score_math-score_tam)*212; 
    }
    else{
        val2=(score_tam-score_math)*305; 
    }

    if(t>=5){
        val3=score_lang*707; 
    }
    else{
        val3=0; 
    }
    ll ans=(val1+val2+val3)*4763LL; 
    cout << ans; 

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   