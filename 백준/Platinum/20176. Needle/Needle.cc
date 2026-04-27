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

int a,b,c,n;
ll finans=0;    
vector <cpx> x(60001),y(60001),z(60001);

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
    for(int i=1; i<f.size(); i<<=1){
        cpx w(cos(ang/i),sin(ang/i));
        for(int j=0; j<f.size(); j+=i<<1){
            cpx z(1,0);
            for(int k=0; k<i; k++){
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

    cin >> a;
    for(int i=0; i<a; i++){
        cin >> n;
        x[n+30000]=cpx(1,0);   // -30000~30000
    }
    cin >> b;
    for(int i=0; i<b; i++){
        cin >> n;
        y[n+30000]=cpx(1,0);
    }
    cin >> c;
    for(int i=0; i<c; i++){
        cin >> n;
        z[n+30000]=cpx(1,0);
    }
    vector <cpx> ans=Multiply(x,z);
    for(int i=0; i<60001; i++){
        finans+=round(ans[i*2].real())*round(y[i].real());
    }
    cout << finans;


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
