/*
    실수 오차를 줄인 복소수 FFT를 계속 시도했지만 계속 틀림
    결국 미뤘던 NTT를 공부하게 됨
    실제로 bit reversal FFT하고 구현 자체는 큰 차이가 없었음
    그저 root of unity를 소수와 원시근으로 대체해줬을 뿐, 그 외에 작동 방식은 동일함 

    https://cp-algorithms.com/algebra/fft.html#number-theoretic-transform
    https://algoshitpo.github.io/2020/05/20/fft-ntt/
    https://github.com/koosaga/olympiad/blob/master/Library/teambook.pdf
    https://rkm0959.tistory.com/187

    NTT와 별개로 조사하던 중 찾은 FFT 설명 잘해놓은 블로그: https://casterian.net/algorithm/%EA%B3%A0%EC%86%8D-%ED%91%B8%EB%A6%AC%EC%97%90-%EB%B3%80%ED%99%98/
*/


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
const ll MOD1=998244353; 
const ll ROOT1=3; 
//NTT만 썼을 때 오버플로우 때문에 틀렸음 / 모듈러 컴퓨테이션을 합쳐주는 과정에서 CRT가 필요함. 
const ll MOD2=2281701377; 
const ll ROOT2=3;

int n,m;

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

vector <ll> multiply_ntt(vector<ll> &a, vector<ll> &b, ll mod, ll root){
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

vector <ll> CRT(vector<ll> &a, vector<ll> &b, ll mod1, ll mod2){
    vector <ll> res(a.size());
    ll inv_mod1=mod_pow(mod1,mod2-2,mod2);
    for(int i=0; i<a.size(); i++){
        ll x1=a[i],x2=b[i];
        ll combined=(x1+((x2-x1+mod2)%mod2)*inv_mod1%mod2*mod1)%(mod1*mod2);
        res[i]=combined;
    }
    return res;
}

vector <ll> multiply(vector<ll> &a, vector<ll> &b){
    vector <ll> res1=multiply_ntt(a,b,MOD1,ROOT1);
    vector <ll> res2=multiply_ntt(a,b,MOD2,ROOT2);
    return CRT(res1,res2,MOD1,MOD2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    cin >> n >> m;
    vector <ll> a(n+1),b(m+1);
    for(int i=0; i<n+1; i++){
        cin >> a[i];
    }
    for(int i=0; i<m+1; i++){
        cin >> b[i];
    }
    vector <ll> ans=multiply(a,b);
    ll fin=0;
    for(int i=0; i<n+m+1; i++){
        fin^=ans[i];
    }
    cout << fin;
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
