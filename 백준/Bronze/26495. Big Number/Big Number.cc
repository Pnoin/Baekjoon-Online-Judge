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

void num(char x){
    if(x=='0'){
        cout << "0000" << '\n' << "0  0" << '\n' << "0  0" << '\n' << "0  0" << '\n' << "0000";
    }
    else if(x=='1'){
        cout << "   1" << '\n' << "   1" << '\n' << "   1" << '\n' << "   1" << '\n' << "   1";
    }
    else if(x=='2'){
        cout << "2222" << '\n' << "   2" << '\n' << "2222" << '\n' << "2" << '\n' << "2222";
    }
    else if(x=='3'){
        cout << "3333" << '\n' << "   3" << '\n' << "3333" << '\n' << "   3" << '\n' << "3333";
    }
    else if(x=='4'){
        cout << "4  4" << '\n' << "4  4" << '\n' << "4444" << '\n' << "   4" << '\n' << "   4";
    }
    else if(x=='5'){
        cout << "5555" << '\n' << "5" << '\n' << "5555" << '\n' << "   5" << '\n' << "5555";
    }
    else if(x=='6'){
        cout << "6666" << '\n' << "6" << '\n' << "6666" << '\n' << "6  6" << '\n' << "6666";
    }
    else if(x=='7'){
        cout << "7777" << '\n' << "   7" << '\n' << "   7" << '\n' << "   7" << '\n' << "   7";
    }
    else if(x=='8'){
        cout << "8888" << '\n' << "8  8" << '\n' << "8888" << '\n' << "8  8" << '\n' << "8888";
    }
    else if(x=='9'){
        cout << "9999" << '\n' << "9  9" << '\n' << "9999" << '\n' << "   9" << '\n' << "   9";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i=0; i<s.size()-1; i++){
        num(s[i]);
        cout << '\n' << '\n';
    }
    num(s[s.size()-1]);
}