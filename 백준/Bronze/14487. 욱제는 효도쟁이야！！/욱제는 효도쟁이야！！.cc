/*
    <메모>
    문제를 잘못 읽어서 1557과 같은 문제로 헷갈림
    1557번이 제곱 ㄴㄴ수를 찾는 문제였다면 이 문제는 제곱 ㄴㄴ수가 아닌 수를 찾는 문제
    그 외의 조건은 같음
    
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 
using namespace std;

int n,total=0,mx=0;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        total+=num;
        mx=max(mx,num);
    }
    cout << total-mx;
    

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
