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

string s;

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
        getline(cin,s);
        if(s=="EOI"){
            break;
        }
        if(s.find("nemo")!=string::npos || s.find("Nemo")!=string::npos || s.find("nEmo")!=string::npos || s.find("neMo")!=string::npos || s.find("nemO")!=string::npos || s.find("NEmo")!=string::npos || s.find("NeMo")!=string::npos || s.find("NemO")!=string::npos || s.find("nEMo")!=string::npos || s.find("nEmO")!=string::npos|| s.find("neMO")!=string::npos || s.find("NEMo")!=string::npos || s.find("NEmO")!=string::npos || s.find("NeMO")!=string::npos || s.find("nEMO")!=string::npos || s.find("NEMO")!=string::npos){
            cout << "Found" << '\n';
        }
        else{
            cout << "Missing" << '\n';
        }
    }


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}