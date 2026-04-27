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

string s;
char bigalpha[30]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char bigalpha2[30]={'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'};
char smallalpha[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char smallalpha2[30]={'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin,s);
    for(int i=0; i<s.size(); i++){
        char temp=s[i];
        if(s[i]>=65 && s[i]<=90){
            for(int j=0; j<26; j++){
                if(bigalpha[j]==s[i]){
                    temp=bigalpha2[j];
                }
            }
        }
        else if(s[i]>=97 && s[i]<=122){
            for(int j=0; j<26; j++){
                if(smallalpha[j]==s[i]){
                    temp=smallalpha2[j];
                }
            }
        }
        cout << temp;
    }
}