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

int n,k,cntr,cntg,cntb;
string s,cur,nexts;

bool all_three_same_or_all_three_diff(char x,char y,char z){
    if(x==y&&y==z){
        return true;
    }
    if(x!=y&&y!=z&&x!=z){
        return true;
    }
    return false;
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

    cin >> n >> k >> s;
    cur=s; 
    nexts=s;
    for(int step=0; step<k; step++){
        for(int i=0; i<n; i++){
            int left=(i-1+n)%n,right=(i+1)%n;
            char x=cur[left],y=cur[i],z=cur[right];
            if(all_three_same_or_all_three_diff(x,y,z)){
                nexts[i]='B';
            }
            else{
                char X,Y;
                if(x==y){
                    X=x; 
                    Y=z;
                }
                else if(x==z){
                    X=x; 
                    Y=y;
                }
                else{
                    X=y; 
                    Y=x;
                }
                if((X=='R'&&Y=='G')||(X=='G'&&Y=='B')||(X=='B'&&Y=='R')){
                    nexts[i]='R';
                }
                else{
                    nexts[i]='G';
                }
            }
        }
        cur=nexts;
    }
    cntr=0; 
    cntg=0; 
    cntb=0;
    for(int i=0; i<n; i++){
        if(cur[i]=='R'){
            cntr++;
        }
        else if(cur[i]=='G'){
            cntg++;
        }
        else if(cur[i]=='B'){
            cntb++;
        }
    }
    cout << cntr << ' ' << cntg << ' ' << cntb;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   