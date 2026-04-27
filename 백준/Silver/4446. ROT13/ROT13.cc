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
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

string s;
char capvow[12]={'A','I','Y','E','O','U','A','I','Y','E','O','U'};
char litvow[12]={'a','i','y','e','o','u','a','i','y','e','o','u'};
char capcon[40]={'B','K','X','Z','N','H','D','C','W','G','P','V','J','Q','T','S','R','L','M','F','B','K','X','Z','N','H','D','C','W','G','P','V','J','Q','T','S','R','L','M','F'};
char litcon[40]={'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f','b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'};

bool isVow(char c){
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y'){
        return true;
    }
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'){
        return true;
    }
    return false;
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
    while(getline(cin,s)){
        for(int i=0; i<s.size(); i++){
            if('A'<=s[i] && s[i]<='Z'){
                if(isVow(s[i])){
                    for(int j=0; j<6; j++){
                        if(capvow[j]==s[i]){
                            cout << capvow[j+3];
                            break;
                        }
                    }
                }
                else{
                    for(int j=0; j<20; j++){
                        if(capcon[j]==s[i]){
                            cout << capcon[j+10];
                            break;
                        }
                    }
                }
            }
            else if('a'<=s[i] && s[i]<='z'){
                if(isVow(s[i])){
                    for(int j=0; j<6; j++){
                        if(litvow[j]==s[i]){
                            cout << litvow[j+3];
                            break;
                        }
                    }
                }
                else{
                    for(int j=0; j<20; j++){
                        if(litcon[j]==s[i]){
                            cout << litcon[j+10];
                            break;
                        }
                    }
                }
            }
            else{
                cout << s[i];
            }
        }
        cout << '\n';
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}