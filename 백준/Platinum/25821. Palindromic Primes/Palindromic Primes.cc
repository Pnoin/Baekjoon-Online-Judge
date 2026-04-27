#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
typedef __int128_t li;

int primearr[12]={2,3,5,7,11,13,17,19,23,29,31,37}; 
/*
    long long int의 범위 내에서는 31까지의 소수들만 체크를 거치면 된다고 증명이 완료되었다함. 
    출처: https://goodbyefin.tistory.com/47
*/
ll n,m,cnt=0;
vector <ll> pal;
vector <li> ans;


li Pow(li a, li n, li p){
    li fin=1; 
    a%=p;
    while(true){
        if(n==0){
            break;
        }
        if(n%2==1){
            fin=(fin*a)%p;
        }
        n/=2;
        a=(a*a)%p;
    }
    return fin;
}

bool Miller_Rabin(li p,li a){ ///짝수 소수는 2밖에 없기 때문에 2를 미리 걸러낸다는 가정하에 P는 항상 홀수
    if(a%p==0){
        return true;
    }
    li k=p-1; ///K의 시작 값은 항상 짝수
    while(true){
        li temp=Pow(a,k,p);
        if(temp==p-1){
            return true;    
        }
        if(k%2==1){
            if(temp==1 or temp==p-1){
                return true;
            }
            else{
                return false;
            }
        }
        k/=2;
    }
}

bool Prime(li p){ 
    if(p==2){
        return true;
    }
    else if(p%2==0){
        return false;
    }
    for(int i=0; i<12; i++){
        li temp=primearr[i]; 
        if(temp==p){
            return true;
        }
        if(!Miller_Rabin(p,temp)){
            return false;
        }
    }
    if(p<=40){
      return false;
    }
    return true;
}

void palindrome11(){
    string s="000000000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[11]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[10]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[9]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    s[8]=l+'0';
                    for(int q=0; q<10; q++){
                        s[4]=q+'0';
                        s[7]=q+'0';
                        for(int w=0; w<10; w++){
                            s[5]=w+'0';
                            s[6]=w+'0';
                            pal.push_back(stoll(s,nullptr,10));
                        }
                    }
                }
            }
        }
    }
}

void palindrome10(){
    string s="00000000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[10]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[9]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[8]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    s[7]=l+'0';
                    for(int q=0; q<10; q++){
                        s[4]=q+'0';
                        s[6]=q+'0';
                        for(int w=0; w<10; w++){
                            s[5]=w+'0';
                            pal.push_back(stoll(s,nullptr,10));
                        }
                    }
                }
            }
        }
    }
}

void palindrome9(){
    string s="0000000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[9]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[8]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[7]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    s[6]=l+'0';
                    for(int q=0; q<10; q++){
                        s[4]=q+'0';
                        s[5]=q+'0';
                        pal.push_back(stoll(s,nullptr,10));
                    }
                }
            }
        }
    }
}

void palindrome8(){
    string s="000000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[8]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[7]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[6]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    s[5]=l+'0';
                    for(int q=0; q<10; q++){
                        s[4]=q+'0';
                        pal.push_back(stoll(s,nullptr,10));
                    }
                }
            }
        }
    }
}

void palindrome7(){
    string s="00000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[7]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[6]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[5]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    s[4]=l+'0';
                    pal.push_back(stoll(s,nullptr,10));
                }
            }
        }
    }
}

void palindrome6(){
    string s="0000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[6]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[5]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[4]=k+'0';
                for(int l=0; l<10; l++){
                    s[3]=l+'0';
                    pal.push_back(stoll(s,nullptr,10));
                }
            }
        }
    }
}

void palindrome5(){
    string s="000000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[5]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[4]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                s[3]=k+'0';
                pal.push_back(stoll(s,nullptr,10));
            }
        }
    }
}

void palindrome4(){
    string s="00000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[4]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[3]=j+'0';
            for(int k=0; k<10; k++){
                s[2]=k+'0';
                pal.push_back(stoll(s,nullptr,10));
            }
        }
    }
}

void palindrome3(){
    string s="0000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[3]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            s[2]=j+'0';
            pal.push_back(stoll(s,nullptr,10));
        }
    }
}

void palindrome2(){
    string s="000";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[2]=i+'0';
        for(int j=0; j<10; j++){
            s[1]=j+'0';
            pal.push_back(stoll(s,nullptr,10));
        }
    }
}

void palindrome1(){
    string s="00";
    for(int i=1; i<10; i++){
        s[0]=i+'0';
        s[1]=i+'0';
        pal.push_back(stoll(s,nullptr,10));
    }
}

void palindrome0(){
    string s="0";
    for(int i=2; i<10; i++){
        s[0]=i+'0';
        pal.push_back(stoll(s,nullptr,10));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    palindrome0();
    palindrome1();
    palindrome2();
    palindrome3();
    palindrome4();
    palindrome5();
    palindrome6();
    palindrome7();
    palindrome8();
    palindrome9();
    palindrome10();
    palindrome11();
    sort(pal.begin(),pal.end());
    for(int i=0; i<pal.size(); i++){
        if(pal[i]<n){
            continue;
        }
        if(pal[i]>m){
            break;
        }
        if(Prime(pal[i])){
            cnt++;
        }
    }
    cout << cnt;
}