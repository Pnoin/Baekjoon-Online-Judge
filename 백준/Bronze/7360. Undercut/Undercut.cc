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

int n,r,ck[10005]={},cc=1;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    bool first=true;
    while(true){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        int a[25]={},b[25]={};
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        int sa=0,sb=0;
        for(int i=0; i<n; i++){
            int x=a[i],y=b[i];
            if(x==y){
                continue;
            }
            int diff=x-y;
            if(diff<0){
                diff=-diff;
            }
            if(diff==1){
                if((x==1 && y==2) || (x==2 && y==1)){
                    if(x<y){
                        sa+=6;
                    }
                    else{
                        sb+=6;
                    }
                }
                else{
                    if(x<y){
                        sa+=x+y;
                    }
                    else{
                        sb+=x+y;
                    }
                }
            }
            else{
                if(x>y){
                    sa+=x;
                }
                else{
                    sb+=y;
                }
            }
        }

        if(!first){
            cout << '\n';
        }
        first=false;
        cout << "A has " << sa << " points. B has " << sb << " points." << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

