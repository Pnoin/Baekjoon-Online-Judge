#include <iostream>

#include <vector>

#include <algorithm>

#include <cstdio>

#include <complex>

#include <cmath>

#include <cstring>

#include <queue>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

typedef long long int ll;

typedef complex<double> cpx;

const double PI = acos(-1); 

string S,T; 

vector <cpx> x;

vector <cpx> y;

/// 1067번 이동이랑 거의 비슷한 문제?

/// FFT함수

void fft(vector <cpx> &f, cpx w){

    /// When base

    if(f.size()==1){  

        return;

    }   

    vector <cpx> odd(f.size()/2);

    vector <cpx> even(f.size()/2);

    for(int i=0; i<f.size(); i++){

        if(i%2==1){

            odd[i/2]=f[i];

        }

        else{

            even[i/2]=f[i];

        }

    }

    fft(even, w*w); 

    fft(odd, w*w);

    cpx wp(1,0);

    for(int i=0; i<f.size()/2; i++){

        f[i]=even[i]+wp*odd[i];

        f[i+f.size()/2]=even[i]-wp*odd[i];

        wp*=w;

    }

}

/// A 벡터와 B 벡터의 convolution을 구하는 과정

vector <cpx> Multiply(vector <cpx> a, vector <cpx> b){

    int MulTwo=1; 

    while(true){

        if(MulTwo >= a.size()+1 || MulTwo >= b.size()+1){

            break;

        }

        MulTwo*=2;

    }

    MulTwo*=2;

    a.resize(MulTwo);

    b.resize(MulTwo);

    vector <cpx> convolution(MulTwo);

    cpx w(cos(2*PI/MulTwo), sin(2*PI/MulTwo));

    /// DFT

    fft(a,w);

    fft(b,w);

    /// Convolution

    for(int i=0; i<MulTwo; i++){

        convolution[i]=a[i]*b[i];

    }

    /// IDFT

    fft(convolution, cpx(1,0)/w);

    for(int i=0; i<MulTwo; i++){

        convolution[i]/=cpx(MulTwo,0);

        convolution[i]=cpx(round(convolution[i].real()), round(convolution[i].imag()));

    }

    return convolution;

}

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin >> S >> T;

    /// 배열 하나는 똑같은 걸 2번, 즉 2배 늘림

    for(int i=0; i<S.size(); i++){

        if(S[i]=='1'){

        	x.push_back(cpx(1,0));        }

        else{

        	x.push_back(cpx(0,0));

        }    

    }

    for(int i=0; i<T.size(); i++){

        if(T[i]=='1'){

        	y.push_back(cpx(1,0));

        }

        else{

        	y.push_back(cpx(0,0));

        }        

    }

    for(int i=0; i<T.size(); i++){

        y.push_back(y[i]);

    }

    reverse(x.begin(), x.end());

    vector <cpx> ans = Multiply(x,y);

    ll mx=0; 

    for(int i=0; i<ans.size(); i++){

        mx=max<ll>(mx, round(ans[i].real()));

    }

    cout << mx;

}