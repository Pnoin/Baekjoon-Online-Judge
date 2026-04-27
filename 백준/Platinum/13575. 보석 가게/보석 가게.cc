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
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 
const ll MOD=998244353; 
const ll ROOT=3; 

int n,k;
vector <ll> x(1024);

ll mod_pow(ll base,ll exp,ll mod){
    ll result=1;
    while(true){
        if(exp==0){
            break;
        }
        if(exp%2){
            result=(result*base)%mod;
        }
        base=(base*base)%mod;
        exp>>=1;
    }
    return result;
}


void ntt(vector <ll> &f, bool inv, ll mod, ll root){
    int reversal=0,temp=1;
    while(true){
        if(temp>=f.size()){
            break;
        }
        int bit=f.size()/2;
        while(true){
            if(reversal<bit){
                break;
            }
            reversal-=bit;
            bit>>=1;
        }
        reversal+=bit;
        if(temp<reversal){
            swap(f[temp],f[reversal]);
        }
        temp++;
    }
    for(int i=2; i<=f.size(); i<<=1){
        ll wlen;
        if(inv){
            wlen=mod_pow(root,mod-1-(mod-1)/i,mod);
        }
        else{
            wlen=mod_pow(root,(mod-1)/i,mod);
        }
        for(int j=0; j<f.size(); j+=i){
            ll w=1;
            for(int k=0; k<i/2; k++){
                ll even=f[j+k],odd=(f[j+k+i/2]*w)%mod;
                if(even+odd<mod){
                    f[j+k]=even+odd;
                }
                else{
                    f[j+k]=even+odd-mod;
                }
                if(even-odd>=0){
                    f[j+k+i/2]=even-odd;
                }
                else{
                    f[j+k+i/2]=even-odd+mod;
                }
                w=(w*wlen)%mod;
            }
        }
    }
    if(inv){
        ll n_inv=mod_pow(f.size(),mod-2,mod);
        for(ll &i:f){
            i=(i*n_inv)%mod;
        }
    }
}

vector <ll> Multiply(vector<ll> &a, vector<ll> &b, ll mod, ll root){
    vector <ll> tempa(a.begin(),a.end()),tempb(b.begin(),b.end());
    int MulTwo=1;
    while(true){
        if(MulTwo>=a.size()+b.size()){
            break;
        }
        MulTwo<<=1;
    }
    tempa.resize(MulTwo);
    tempb.resize(MulTwo);
    ntt(tempa,false,mod,root);
    ntt(tempb,false,mod,root);
    for (int i=0; i<MulTwo; i++) {
        tempa[i]=(tempa[i]*tempb[i])%mod;
    }
    ntt(tempa,true,mod,root);
    return tempa;
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

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        x[num]=1,0;
    }
    vector <ll> y(x.begin(),x.end());
    k--;
    while(true){
        if(k==0){
            break;
        }
        if(k%2){
            y=Multiply(x,y,MOD,ROOT);
        }
        x=Multiply(x,x,MOD,ROOT);
        k/=2;
    }
    for(int i=0; i<y.size(); i++){
        if(y[i]){
            cout << i << ' ';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
