#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
 
int m,sg;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> sg;
    for(int i=1; i<m; i++){
        int num;
        cin >> num;
        sg=sg^num;
    }
    if(sg==0){
        cout << "cubelover";
    }
    else{
        cout << "koosaga";
    }
}