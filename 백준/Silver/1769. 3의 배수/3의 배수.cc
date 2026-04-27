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
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

string s;
int cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> s;
    while(true){
        if(s.size()==1){
            break;
        }
        int total=0;
        for(int i=0; i<s.size(); i++){
            total+=s[i]-'0';
        }
        s=to_string(total);
        cnt++;
    }
    cout << cnt << '\n';
    if(stoi(s)%3){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}