/*
    https://www.acmicpc.net/board/view/76459
    이거 때문에 계속 틀렸던 걸로 추측됨
*/

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
const long double PI = acos(-1); 

string x;
int n,start=1,match=0,arr[2000005]={};
vector <int> v; //first letter location 

/*
    정올 D-5 KMP 알고리즘

    <공부자료>
    https://bowbowbow.tistory.com/6
    https://injae-kim.github.io/dev/2020/07/23/all-about-kmp-algorithm.html (그림 설명 되게 잘되어있음. 복습용으로 좋은 블로그)
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    start=1;
    match=0;
    v.clear();
    cin >> n >> x;
    int X=x.size(); 
    while(true){
        if(start+match>=X){
            break;
        }
        if(x[start+match]==x[match]){
            match++;
            arr[start+match-1]=match;
        }
        else{
            if(match==0){
                start++;
            }
            else{
                start+=match-arr[match-1];
                match=arr[match-1];
            }
        }
    }
    cout << n-arr[n-1] << '\n';
}