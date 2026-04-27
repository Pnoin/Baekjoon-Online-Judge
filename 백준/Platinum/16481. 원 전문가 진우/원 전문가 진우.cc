/*
  14346 Radioactive Islands (Small) 코드에서 연장

  전체 과정이 너무 길다보니 풀이과정은 티스토리에 나중에 따로 정리해놓기
 
  모든 참고자료 정리:
  
  선적분:
  https://m.blog.naver.com/cronix/220334075353
  https://m.blog.naver.com/cindyvelyn/221828338012
  
  오일러 라그랑주 방정식
  https://namu.wiki/w/오일러%20방정식#s-2
  
  룽게 쿠타
  https://lpsa.swarthmore.edu/NumInt/NumIntFourth.html
  https://math.okstate.edu/people/yqwang/teaching/math4513_fall11/Notes/rungekutta.pdf
  
  Shooting method
  https://reference.wolfram.com/language/tutorial/NDSolveBVP.html
  
  Simpson 1/3 rule
  https://www.cuemath.com/simpsons-rule-formula/
  https://atozmath.com/example/CONM/NumeInte.aspx?q=S13&q1=E1
  https://youtu.be/AamSY0Naly0?si=5244BtA6iygYXypw
  
  전체적인 문제 아이디어
  #solved.ac discord 14346,14347 thread

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
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
const ld PI=acos(-1); 
const ll INF=1e18;

double a,b,c;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
	cin >> a >> b >> c;
	cout << fixed; 
	cout.precision(10);
	cout << (a*b*c)/(a*b+a*c+b*c);
   
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}