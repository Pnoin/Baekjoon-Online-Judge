#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    cin >> s;
    int ck=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='x'){
            ck=1;
            break;
        }
    }
    if(ck==0){
        cout << 0;
        return 0;
    }
    string temp="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='x'){
            break;
        }
        temp+=s[i];
    }
    if(temp.size()==0){
        cout << 1;
    }
    else{
        if(temp=="-"){
            cout << -1;
        }
        else{
            cout << temp;
        }
    }
}