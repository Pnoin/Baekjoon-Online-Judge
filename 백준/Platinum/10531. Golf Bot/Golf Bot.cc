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

int n, m, num, cnt=0; 
vector <cpx> x(200005);

/*
1067번 이동과 다른 점:
처음에 입력받은 배열 하나만 가지고 FFT를 돌리면 됨 (예제. 1 3 5 / 1 3 5)
입력받은 다항식의 coefficient라고 생각하였을 때 (a1, a2x, a3x^2, a4x^3...)
계수가 0이 아닌 항의 지수가 처음에 입력받은 숫자들을 조합하여 만들 수 있는 숫자들. 
complete in 2 strokes or less --> 이 조건 덕에 기본적인 FFT로 값 찾는 게 가능
*/

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
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        x[num]=cpx(1,0);
    }
    x[0]=1;
    vector <cpx> ans = Multiply(x,x);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        if(ans[num].real()!=0){
            cnt++;
        }
    } 
    cout << cnt;
}