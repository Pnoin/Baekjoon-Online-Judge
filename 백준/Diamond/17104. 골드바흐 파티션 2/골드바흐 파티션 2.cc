#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int t; 
vector <cpx> x(500005),y(500005);
vector <int> prime;
bool ck[1000005]={};

void sieve(){
    for(int i=2; i<=1000000; i++){
        if(ck[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i*2; j<=1000000; j+=i){
            ck[j]=true;
        }
    }
}

/*
    FFT를 처음에 잘못 구현했는지 계속 시간 초과가 뜨길래 더 빠른 FFT를 찾아보게됨
    참고: https://restudycafe.tistory.com/563
    (처음에 구현했던 bit reversal 방식과 동일하지만 코드 순서만 약간 바뀜. 이게 유의미한 차이가 있는지 잘 모르겠으나 테스트용으로 제출)
*/
void fft(vector <cpx> &f, bool inv){
    int reversal=0,temp=1;
    double ang=PI;
    if(inv){
      ang*=-1;
    }
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
    for(register int i=1; i<f.size(); i<<=1){
        cpx w(cos(ang/i),sin(ang/i));
        for(register int j=0; j<f.size(); j+=i<<1){
            cpx z(1,0);
            for(register int k=0; k<i; k++){
                cpx even=f[j+k],odd=f[j+k+i]*z;
                f[j+k]=even+odd;
                f[j+k+i]=even-odd;
                z*=w;
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
        MulTwo<<=1;
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
        x[prime[i]/2]=cpx(1,0);
        y[prime[i]/2]=cpx(1,0);
    }
    vector <cpx> ans=Multiply(x,y);
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cin >> num;
        if(num==4){
            cout << 1 << '\n';
            continue;
        }
        cout << ceil(round(ans[num/2-1].real())/2) << '\n';
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}