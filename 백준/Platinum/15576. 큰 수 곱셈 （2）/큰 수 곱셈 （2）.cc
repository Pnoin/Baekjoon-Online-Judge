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

/* 
    전체적 풀이: 각 자리 수의 convolution의 합 = 곱셈
    일반적인 곱셈: O(n^2)
    카라추바 곱셈: O(n^log(3))
    FFT 빠른 곱셈: O(nlog(n))
    
    n <= 3e5
    Worst case: 
    일반 곱셈: 9e10
    카라추바: 5e8
    FFT: 6e6
    시간제한 2초라 카라추바로 풀기에도 약간 애매할 듯 해서 FFT 선택해야함. 
*/

string n,m;      /// n,m < 10e300000
vector <cpx> x;
vector <cpx> y;

/// 개념 공부할 때 참고한 블로그: https://m.blog.naver.com/kks227/221633584963

/// 1067번 이동 풀 때 내가 사용된 FFT 코드
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
        if(MulTwo >= a.size()+b.size()){     /// 범위 잘못 정해놓고 삽질 중이였음(6트)
            break;                           /// 범위에서 또 틀림 (7트) 범위 이렇게 하면 시간초과남
        }
        MulTwo*=2;
    }
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
    cin >> n >> m;
    if(n=="0" || m=="0"){ /// 0 처리 까먹음 (5트)
        cout << 0;
        return 0;
    }
    reverse(n.begin(),n.end());
    reverse(m.begin(),m.end());
    for(int i=0; i<n.size(); i++){  
        x.push_back(cpx(n[i]-48,0));
    }
    for(int i=0; i<m.size(); i++){
        y.push_back(cpx(m[i]-48,0));
    }
    vector <cpx> get_ans = Multiply(x,y); ///FFT
    /// 올림 처리를 안해서 틀렸음  (1트)
    vector <ll> ans(get_ans.size());
    for(int i=0; i<get_ans.size(); i++){
        ans[i]=round(get_ans[i].real());
    }
    for(int i=0; i<n.size()+m.size()-1; i++){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    int zero_idx=ans.size()-1;
    ///뒤에 들어오는 0 처리를 안해서 틀림 (ex. 1*2 = 2000)  (2트)
    ///0 처리 잘못해서 틀림 (3트)
    for(int i=ans.size()-1; i>=0; i--){  
        /// 이거 범위를 ans.size()로 해놨어가지고 필요한 0까지 지웟엇음. 10*10이 계속 1나왔었음 (4트)
        if(ans[i]==0){
            zero_idx--;
        }
        else{
            break;
        }
    }
    for(int i=zero_idx; i>=0; i--){
        cout << ans[i];
    }
}