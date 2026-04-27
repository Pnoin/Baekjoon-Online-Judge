#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	while (getline(cin,s)){
	    int a=0,b=0,c=0,d=0;
	    for(int i=0; i<s.size(); i++){	
		    if(s[i]>='a' && s[i]<='z'){
                a++;
            }
		    else if(s[i]>='A' && s[i]<='Z'){
                b++;
            }
		    else if(s[i]>='0' && s[i]<='9'){
                c++;
            }
		    else if(s[i]==' '){
                d++;
	        }
        }
	    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
}