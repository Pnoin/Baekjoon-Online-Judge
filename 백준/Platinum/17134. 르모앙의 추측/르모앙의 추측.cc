/*
    쿨리-튜키 알고리즘을 이용한 재귀형 FFT로는 시간 초과가 났음
    Bit Reversal을 이용한 비재귀형 FFT로 시도
    이 버전의 FFT는 다음의 블로그로 공부를 하였음 (복습용 기록): https://fullyz.tistory.com/24
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <time.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int t; 
vector <cpx> x(1000005),y(1000005);
vector <int> prime;
bool ck[1000005]={};

void sieve(){
    for(int i=2; i<=1000000; i++){
        if(ck[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i; j<=1000000; j+=i){
            ck[j]=true;
        }
    }
}

void fft(vector <cpx> &f, bool inv){
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
            bit/=2;
        }
        reversal+=bit;
        if(temp<reversal){
            swap(f[temp],f[reversal]);
        }
        temp++;
    }
    vector <cpx> w(f.size()/2);
    double ang=PI*2/f.size();
    if(inv){
      ang*=-1;
    }
    for(int i=0; i<f.size()/2; i++){
        w[i]=cpx(cos(ang*i),sin(ang*i));
    }
    for(int i=2; i<=f.size(); i*=2){
        for(int j=0; j<f.size(); j+=i){
            for(int k=0; k<i/2; k++){
                cpx even=f[j+k],odd=f[j+k+i/2]*w[k*f.size()/i];
                f[j+k]=even+odd;
                f[j+k+i/2]=even-odd;
            }
        }
    }
    if(inv){
      for(int i=0; i<f.size(); i++){
        f[i]/=f.size();
      } 
    }
}

vector <cpx> Multiply(vector <cpx> a, vector <cpx> b){
    int MulTwo=1; 
    while(true){
        if(MulTwo>=a.size()+b.size()){
            break;
        }
        MulTwo*=2;
    }
    a.resize(MulTwo);
    b.resize(MulTwo);
    vector <cpx> convolution(MulTwo);
    fft(a,false);
    fft(b,false);
    for(int i=0; i<MulTwo; i++){
        convolution[i]=a[i]*b[i];
    }
    fft(convolution,true);
    return convolution;
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
    sieve();
    for(int i=1; i<prime.size(); i++){
        x[prime[i]]=cpx(1,0);
    }
    for(int i=0; i<prime.size(),prime[i]<=500000; i++){
        y[prime[i]*2]=cpx(1,0);
    }
    vector <cpx> ans=Multiply(x,y);
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cin >> num;
        cout << round(ans[num].real()) << '\n';
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}