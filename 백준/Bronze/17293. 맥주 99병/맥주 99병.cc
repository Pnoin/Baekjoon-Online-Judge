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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=n; i>=0; i--){
        if(i==0){
            if(n==1){
                cout << "No more bottles of beer on the wall, no more bottles of beer." << '\n' << "Go to the store and buy some more, " << n<< " bottle of beer on the wall."<< '\n';
            }
            else{
                cout << "No more bottles of beer on the wall, no more bottles of beer." << '\n' << "Go to the store and buy some more, " << n<< " bottles of beer on the wall."<< '\n';
            }
        }
        else if(i==1){
            cout << "1 bottle of beer on the wall, 1 bottle of beer." << '\n' << "Take one down and pass it around, no more bottles of beer on the wall." << '\n';
        }
        else{
            if(i-1==1){
                cout << i << " bottles of beer on the wall, " << i << " bottles of beer." << '\n' << "Take one down and pass it around, " << i-1 << " bottle of beer on the wall." << '\n';
            }
            else{
                cout << i << " bottles of beer on the wall, " << i << " bottles of beer." << '\n' << "Take one down and pass it around, " << i-1 << " bottles of beer on the wall." << '\n';
            }
        }
        cout << '\n';
    }
}