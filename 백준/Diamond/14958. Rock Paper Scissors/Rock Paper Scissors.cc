#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,m; 
unsigned int i;
ll mx=0;
string s1,s2;
vector <cpx> x,y;

/// FFT함수 
void fft(vector <cpx> &f, cpx w){
    /// When base
    if(f.size()==1){  
        return;
    }   
    vector <cpx> odd(f.size()/2);
    vector <cpx> even(f.size()/2);
    for(i=0; i<f.size(); i++){
        if(i&1){
            odd[i/2]=f[i];
        }
        else{
            even[i/2]=f[i];
        }
    }
    fft(even, w*w); 
    fft(odd, w*w);
    cpx wp(1,0);
    for(i=0; i<f.size()/2; i++){
        f[i]=even[i]+wp*odd[i];
        f[i+f.size()/2]=even[i]-wp*odd[i];
        wp*=w;
    }
}

/// A 벡터와 B 벡터의 convolution을 구하는 과정
vector <cpx> Multiply(vector <cpx> a, vector <cpx> b){
    int MulTwo=1; 
    while(true){
        ///if(MulTwo>=a.size()+b.size()+1){
        if(MulTwo>=max(a.size(),b.size())+1){
            break;
        }
        MulTwo<<=1;
    }
    MulTwo<<=1;
    a.resize(MulTwo);
    b.resize(MulTwo);
    vector <cpx> convolution(MulTwo);
    cpx w(cos((PI*2)/MulTwo), sin((PI*2)/MulTwo));
    /// DFT
    fft(a,w);
    fft(b,w);
    /// Convolution
    for(i=0; i<MulTwo; i++){
        convolution[i]=a[i]*b[i];
    }
    /// IDFT
    fft(convolution, cpx(1,0)/w);
    for(i=0; i<MulTwo; i++){
        convolution[i]/=cpx(MulTwo,0);
        convolution[i]=cpx(round(convolution[i].real()), round(convolution[i].imag()));
    }
    return convolution;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s1 >> s2;
    for(i=0; i<s1.size(); i++){
        if(s1[i]=='S'){
            x.push_back(cpx(1,0));
        }
        else{
            x.push_back(cpx(0,0));
        }
    }
    for(i=0; i<s2.size(); i++){
        if(s2[i]=='R'){
            y.push_back(cpx(1,0));
        }
        else{
            y.push_back(cpx(0,0));
        }
    }
    reverse(x.begin(), x.end());
    vector <cpx> ans = Multiply(x,y);
    
    for(i=s1.size(); i>0; i--){
        if(s1[i-1]=='P'){
            x[s1.size()-i]=cpx(1,0);
        }
        else{
            x[s1.size()-i]=cpx(0,0);
        }
    }
    for(i=0; i<s2.size(); i++){
        if(s2[i]=='S'){
            y[i]=cpx(1,0);
        }
        else{
            y[i]=cpx(0,0);
        }
    }
    vector <cpx> ans2 = Multiply(x,y);
    
    for(i=s1.size(); i>0; i--){
        if(s1[i-1]=='R'){
            x[s1.size()-i]=cpx(1,0);
        }
        else{
            x[s1.size()-i]=cpx(0,0);
        }
    }
    for(i=0; i<s2.size(); i++){
        if(s2[i]=='P'){
            y[i]=cpx(1,0);
        }
        else{
            y[i]=cpx(0,0);
        }
    }
    vector <cpx> ans3 = Multiply(x,y);
    
    for(i=0; i<n; i++){
        ///cout << round(ans[i].real()) << ' ' <<round(ans2[i].real()) << ' ' <<round(ans3[i].real()) <<'\n';
        mx=max<ll>(mx, round(ans[i].real())+round(ans2[i].real())+round(ans3[i].real()));
    }
    cout << mx;
}