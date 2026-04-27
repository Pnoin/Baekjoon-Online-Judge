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

string n,m;     
vector <cpx> x,y;

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
            bit>>=1;
        }
        reversal+=bit;
        if(temp<reversal){
            swap(f[temp],f[reversal]);
        }
        temp++;
    }
    double ang=PI;
    if(inv){
      ang*=-1;
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

    cin >> n >> m;
    if(n=="0" || m=="0"){ 
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
    vector <cpx> get_ans = Multiply(x,y);
    vector <ll> ans(get_ans.size());
    for(int i=0; i<get_ans.size(); i++){
        ans[i]=round(get_ans[i].real());
    }
    for(int i=0; i<n.size()+m.size()-1; i++){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    int zero_idx=ans.size()-1;
    for(int i=ans.size()-1; i>=0; i--){  
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
    
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}