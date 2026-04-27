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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n, arr[30]={}, total=0;
string s;
stack <char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        while(!st.empty()){
            st.pop();
        }
        memset(arr,0,sizeof(arr));
        int ck=1;
        st.push(s[0]);
        arr[s[0]-97]++;
        for(int j=1; j<s.size(); j++){
            if(st.top()!=s[j] && arr[s[j]-97]==0){
                st.push(s[j]);
                arr[s[j]-97]++;
            }
            else if(st.top()!=s[j] && arr[s[j]-97]==1){
                ck=0;
                break;
            }
        }
        total+=ck;
    }
    cout << total;
}