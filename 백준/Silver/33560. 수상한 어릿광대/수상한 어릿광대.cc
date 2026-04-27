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

int n,arr[100005]={},ans1=0,ans2=0,ans3=0,ans4=0;

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
        cin >> arr[i];
    }
    int p=1,turn=4,score=0,t=0;
    for(int i=0; i<n; i++){
        if(t>240){
            if(score>=35 && score<65){
                ans1++;
            } 
            else if(score>=65 && score<95){
                ans2++;
            } 
            else if(score>=95 && score<125){
                ans3++;
            } 
            else if(score>=125){
                ans4++;
            }
            score=0;
            p=1;
            t=0;
            turn=4;
            i--;
            continue;
        }
        if(arr[i]==1){
            if(score>=35 && score<65){
                ans1++;
            } 
            else if(score>=65 && score<95){
                ans2++;
            } 
            else if(score>=95 && score<125){
                ans3++;
            } 
            else if(score>=125){
                ans4++;
            }
            score=0;
            p=1;
            t=0;
            turn=4;
        }
        else{
            if(arr[i]==2){
                if(p>1){
                    p/=2;
                }
                else if(p==1){
                    turn+=2;
                }
            }
            else if(arr[i]==4){
                t+=56;
            }
            else if(arr[i]==5){
                if(turn>1){
                    turn--;
                }
            }
            else if(arr[i]==6){
                if(p<32){
                    p*=2;
                }
            }
            score+=p;
            t+=turn;
        }
    }
    cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n' << ans4;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}