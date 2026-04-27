#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> pll;

string s;
int total=0,arr[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='c'){
            if(s[i+1]=='-' || s[i+1]=='='){
                arr[i+1]=-1;
            }
        }
        else if(s[i]=='d'){
            if(s[i+1]=='-'){
                arr[i+1]=-1;
            }
            else if(s[i+1]=='z'){
                if(i+2<s.size()){
                    if(s[i+2]=='='){
                        arr[i+1]=-1;
                        arr[i+2]=-1;
                    }
                }
            }
        }
        else if(s[i]=='l' && s[i+1]=='j'){
            arr[i+1]=-1;
        }
        else if(s[i]=='n' && s[i+1]=='j'){
            arr[i+1]=-1;
        }
        else if(s[i]=='s' && s[i+1]=='='){
            arr[i+1]=-1;
        }
        else if(s[i]=='z' && s[i+1]=='='){
            arr[i+1]=-1;
        }
    }
    for(int i=0; i<s.size(); i++){
        total++;
        total+=arr[i];
    }
    cout << total;
}