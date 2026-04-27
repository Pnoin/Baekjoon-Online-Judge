/*
    바구니 딱 3개 기준: 바구니 하나의 그런디 수 g(x) --> g(0)=0 / x>0 일 때 g(x)=mex{g(x-1)~g(x-m)}
        따라서 g(x)=x mod (m+1)
        공 갯수가 각각 (a,b,c)라고 치면 G=g(a)^g(b)^g(c)=(a mod (m+1))^(b mod (m+1))^(c mod (m+1))
        G!=0 이면 메이지 승, G=0이면 리샤 승

    바구니 N개 중 3개 뽑는단 기준: g(a)^g(b)^g(c)=0(리샤 승)을 만족하는 {a,b,c}의 개수
        각 바구니의 나머지를 계산하고 각 값의 등장 횟수를 카운트해서 저장
        이렇게 해서 xor이 0인 {a,b,c} 조합을 찾아서 세면 됨
        1. a,b,c 세 값이 모두 0
        2. a,b,c 중 두 값이 같고 나머지 하나가 0
        3. c=a^b <=> a^b^c=0
    
    Naive 기준 O(M^2), 각 바구니의 나머지 종류 (M+1)
    --> r[i] = 바구니[i] mod (m+1)이라 정의, g(x)=x mod (m+1)이라 정의하고,
    --> 각 나머지의 등장 빈도를 저장하는 배열을 만들고(ex. cnt[r]), xor 컨볼루션으로 g[c]=r[i]^r[j]=c인 개수라 표현
    그럼 모든 g[c]*cnt[c]를 더한게 답 (단, 인덱스 중복도 포함된 값임) --> 후처리

    아까 위에서 말한 3케이스:
    1. 똑같은 3값 --> cnt[0] 갯수
    2. 2개만 같은 경우 --> 3가지 패턴이라 ({a,a,b},{a,b,a},{b,a,a})라 3cnt[0](n-1)
    그럼 아까 위에서 더한 중복도 포함된 값에서 cnt[0]과 3cnt[0](n-1)를 빼고
    이 값을 6으로 나눈게 정답 (서로 다른 3가지 숫자로 이루어진 한 쌍에 대하여 가능한 순열은 6가지라서)
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
#include <numeric>
#include <set>
#include <map>
#include <regex>
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int n,m,k=1;
ll x,ans=0;

void fwht(vector <ll> &f,bool inv){
    if(f.size()==1){
        return;
    }
    vector <ll> odd(f.size()/2),even(f.size()/2);
    for(int i=0; i<f.size(); i++){
        if(i%2){
            odd[i/2]=f[i];
        }
        else{
            even[i/2]=f[i];
        }
    }
    fwht(even,inv);
    fwht(odd,inv);
    for(int i=0; i<f.size()/2; i++){
        ll u=even[i],v=odd[i];
        f[i]=u+v;
        f[i+f.size()/2]=u-v;
    }
}

vector <ll> Multiply(vector <ll> a,vector<ll> b){
    int MulTwo=1;
    while(true){
        if(MulTwo>=a.size() || MulTwo>=b.size()){
            break;
        }
        MulTwo*=2;
    }
    a.resize(MulTwo);
    b.resize(MulTwo);
    vector <ll> convolution(MulTwo);
    fwht(a,false);
    fwht(b,false);
    for(int i=0; i<MulTwo; i++){
        convolution[i]=a[i]*b[i];
    }
    fwht(convolution,true);
    for(int i=0; i<MulTwo; i++){
        convolution[i]/=MulTwo;
    }
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

    cin >> n >> m;
    while(k<m+1){
        k<<=1;
    }
    vector <ll> cnt(k,0);
    for(int i=0; i<n; i++){
        cin >> x;
        int r=(x%(m+1));
        cnt[r]++;
    }
    vector <ll> g=Multiply(cnt,cnt);
    for(int i=0; i<k; i++){
        ans+=g[i]*cnt[i];
    }
    cout << (ans-cnt[0]*(3*n-2))/6;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

