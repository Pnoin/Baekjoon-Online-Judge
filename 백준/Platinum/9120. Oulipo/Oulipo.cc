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

string x,y;
int t,start=1,match=0,arr[2000005]={};
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
    cin >> t;
    for(int test=0; test<t; test++){
        start=1;
        match=0;
        v.clear();
        cin >> y >> x;
        int X=x.size(),Y=y.size(); 
        memset(arr,0,sizeof(arr));
        while(true){
            if(start+match>=Y){
                break;
            }
            if(y[start+match]==y[match]){
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
        start=0;
        match=0;
        while(true){
            if(start>X-Y){
                break;
            }
            if(match<Y && x[start+match]==y[match]){
                match++;
                if(match==Y){
                    v.push_back(start);
                }
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
        cout << v.size() << '\n';
    }
}