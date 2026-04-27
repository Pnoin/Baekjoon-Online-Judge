#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

string s;

bool isvowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> s;
        if(s=="end"){
            break;
        }
        int ck=0;
        for(int i=0; i<s.size(); i++){
            if(isvowel(s[i])){
                ck++;
                break;
            }
        }
        if(s.size()>2){
            for(int i=0; i<s.size()-2; i++){
                if(isvowel(s[i]) && isvowel(s[i+1]) && isvowel(s[i+2])){
                    ck--;
                    break;
                }
                else if(!isvowel(s[i]) && !isvowel(s[i+1]) && !isvowel(s[i+2])){
                    ck--;
                    break;
                }
            }
        }
        ck++;
        if(s.size()>1){
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==s[i+1]){
                if(s[i]!='e' && s[i]!='o'){
                    ck--;
                    break;
                }
            }
        }
        }
        ck++;
        if(ck==3){
            cout << '<' << s << "> is acceptable." << '\n';
        }
        else{
            cout << '<' << s << "> is not acceptable." << '\n';
        }
    }
}