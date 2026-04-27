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

int n;
queue <int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        int num;
        cin >> s;
        if(s=="push"){
            cin >> num;
            q.push(num);
        }
        else if(s=="pop"){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s=="size"){
            cout << q.size() << '\n';
        }
        else if(s=="empty"){
            cout << q.empty() << '\n';
        }
        else if(s=="front"){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
            }
        }
        else{
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.back() << '\n';
            }
        }
    }
}