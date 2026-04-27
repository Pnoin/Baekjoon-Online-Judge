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
const double PI = acos(-1); 
const ll INF = 1e18;

string board[10][2]={{"11", "A B C D E F G H J L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A B C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A B C F G H L M"}};
int n;

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
    cout << board[n-1][0] << '\n' << board[n-1][1];



    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
