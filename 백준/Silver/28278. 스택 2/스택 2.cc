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
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n;
stack <int> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num==1){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(num==2){
            if(st.empty()){
                cout << -1 << '\n'; 
            }
            else{
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(num==3){
            cout << st.size() << '\n';
        }
        else if(num==4){
            if(st.empty()){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            if(st.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << st.top() << '\n';
            }
        }
    }
}