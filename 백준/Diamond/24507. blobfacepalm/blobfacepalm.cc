//https://oeis.org/A059106    Langford Pairing

//https://oeis.org/A132291    


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n;
vector <int> v;

void fill1(){
    int cur=n-1;
    while(true){
        if(cur==1){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }
    v.push_back(n-2);
    while(true){
        if(cur==n-1){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }
    v.push_back(n/2-2);

    cur=n-4;
    while(true){
        if(cur==n/2){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }

    cur-=4;

    while(true){
        if(cur==2){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }

    v.push_back(n-2);
    v.push_back(n/2-2);

    while(true){
        if(cur==n/2-4){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }

    v.push_back(0);
    v.push_back(0);

    cur=n/2;
    while(true){
        if(cur==n-4){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }
}

void fill2(){
    int cur=n-1;
    while(true){
        if(cur==2){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }
    v.push_back(n/2+1);
    v.push_back(n-2);

    while(true){
        if(cur==n-1){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }

    v.push_back(n/2+1);

    cur=n-4;
    while(true){
        if(cur==n/2+3){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }
    cur=n/2-1;
    while(true){
        if(cur==1){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur-=2;
    }

    v.push_back(n-2);
    while(true){
        if(cur==n/2-1){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }
    v.push_back(0);
    v.push_back(0);
    cur=n/2+3;
    while(true){
        if(cur==n-4){
            v.push_back(cur);
            break;
        }
        v.push_back(cur);
        cur+=2;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
	if(n%4==2 || n%4==3){
        cout << "No";
        return 0;
    }
    cout << "Yes" << '\n';
    if(n==1){
        cout << "0 0";
        return 0;
    }
    else if(n==4){
        cout << "1 2 1 3 2 0 0 3";
        return 0;
    }
    else if(n==5){
        cout << "0 0 2 3 4 2 1 3 1 4";
        return 0;
    }
    else if(n==8){
        cout << "1 2 1 3 2 6 7 3 4 5 0 0 6 4 7 5";
        return 0;
    }
    else if(n==9){
        cout << "8 3 7 2 6 3 2 4 5 8 7 6 4 1 5 1 0 0";
        return 0;
    }
    if(n%4){
        fill2();
    }
    else{
        fill1();
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
}

