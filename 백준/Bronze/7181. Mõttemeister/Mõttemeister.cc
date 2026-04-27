#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <time.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;
const double PI = acos(-1); 

string s;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> n;
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        int x=0,y=0;
        for(int j=0; j<4; j++){
            if(a[j]==s[j]){
                x++;
                y++;
            }
            else{
                for(int k=0; k<4; k++){
                    if(j==k){
                        continue;
                    }
                    if(a[j]==s[k]){
                        x++;
                        break;
                    }
                }
            }
        }
        cout << x << ' ' << y << '\n';
    }
}