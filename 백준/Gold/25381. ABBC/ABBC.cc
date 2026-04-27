#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <deque>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

deque <int> dq;
int cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='B'){
            dq.push_back(i);
            cnt++;
        }
    }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='A' && !dq.empty()){
            if(i<dq.back()){
                dq.pop_back();
            }
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='C' && !dq.empty()){
            if(i>dq.front()){
                dq.pop_front();
            }
        }
    }
    cout << cnt-dq.size(); 
}