#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

ll n,k, arr[2005][2005]={},total=1;
int m;
vector <int> a;
vector <int> b;

void solveA(ll x, int y){
    while(x>0){
        int rem=x%y;
        a.push_back(rem);
        x/=y;
    }
}

void solveB(ll x, int y){
    while(x>0){
        int rem=x%y;
        b.push_back(rem);
        x/=y;
    }
}

ll mul(int x, int y){
    if (y>x) {
        return 0;
    }
    if (x/2<y) {
        y=x-y;
    }
    if (arr[x][y] != -1) {
        return arr[x][y];
    }
    if (y == 0){
        return arr[x][y] = 1;
    } 
    else if (y == 1) {
        return arr[x][y] = x;
    }
    return arr[x][y]=(mul(x-1, y-1)+mul(x-1,y))%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> m;
    solveA(n,m);
    solveB(k,m);
    memset(arr,-1,sizeof(arr));
    for(int i=0; i<b.size(); i++){
        total*=mul(a[i],b[i]);
        total%=m;
    }
    cout << total;
}