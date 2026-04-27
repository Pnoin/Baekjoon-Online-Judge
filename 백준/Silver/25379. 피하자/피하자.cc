#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

int n,odd,even;
ll totalodd=0, totaleven=0;
vector<int>v;
queue <int> q;
/* 
ex) 10111001
짝:3
홀:5
짝수가 왼쪽, 홀수가 오른쪽
000 11111
101 11001
. .   ..  
012 34567 

5-0=5
6-2=4
9

홀수가 왼쪽, 짝수가 오른쪽
11111 000
10111 001
 .      .
01234 567

7-1=6
6

*/

void ODD(){
    for(int i=odd; i<n; i++){
        if(v[i]==1){
            q.push(i);
        }
    }
    for(int i=0; i<odd; i++){
        if(v[i]==0){
            totalodd+=q.front()-i;
            q.pop();
        }
    }
}

void EVEN(){
    for(int i=even; i<n; i++){
        if(v[i]==0){
            q.push(i);
        }
    }
    for(int i=0; i<even; i++){
        if(v[i]==1){
            totaleven+=q.front()-i;
            q.pop();
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        if(num%2==0){
            v.push_back(0);
            even++;
        }
        else{
            v.push_back(1);
            odd++;
        }
    }
    ODD();
    EVEN();
    cout << min(totalodd, totaleven);
}
