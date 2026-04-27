/*
    3일간 생각해보았는데도 생각이 도무지 안나서 이미 푼 사람에게 해설을 듣고 풀게됨

    첫 시도: 
    17104번 골드바흐 파티션 2를 이미 풀었음. 문제도 큰 차이가 없어보여 이와 비슷한 방식으로 구현함.
    2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다. --> 소수를 전처리로 구해놓아서 배열에 저장 (소수번째 인덱스를 1, 그 외는 0), 배열 복사본을 만들어서 두 배열을 FFT로 합성곱
    이렇게 해서 저 문제는 맞았음

    골드바흐 트리플도 결국에 따지고 보면 FFT를 한 번 더 하면 되는 거 아닌가 하는 생각으로 접근 --> WA

    우선 틀린 이유는 "세 소수의 순서만 다른 것은 같은 트리플이다."라는 조건
    사실 이 조선은 골드바흐 파티션 2에도 있는 조건이지만, 2개 밖에 없는 상황에선 처리하기가 간단했음 

    3개인 경우 그냥 단순하게 FFT 2번 (배열 3개를 곱함)를 한 뒤 나온 결과값을 3을 나누면 되지 않을까 생각했지만, 예제 몇 개 직접 손으로 해보니 예외가 생각보다 쉽게 나옴
    즉, 정수론적으로 다시 접근해볼 필요가 생김

    세 개의 소수의 합 --> 각각 a,b,c라고 치면
    a,b,c가 모두 다른 경우
    WLOG a와 b만 같은 경우
    a,b,c가 모두 같은 경우
    이렇게 3가지 케이스가 존재함

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

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    getline(cin,s);
    bool ck1=0,ck2=0,ck3=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='U'){
            ck1=true;
        }
        if(s[i]=='C' && ck1){
            ck2=true;
        }
        if(s[i]=='P' && ck2){
            ck3=true;
        }
        if(s[i]=='C' && ck3){
            cout << "I love UCPC";
            return 0;
        }
    }
    cout << "I hate UCPC";

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
