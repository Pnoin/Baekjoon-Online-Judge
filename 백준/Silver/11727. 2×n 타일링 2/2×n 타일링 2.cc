#include <iostream>
using namespace std;

int main(){
    int n, arr[1005]={};
    cin >> n;
    arr[1]=1;
    arr[2]=3;
    for(int i=3; i<=n; i++){
        arr[i]=(arr[i-1]+2*arr[i-2])%10007;
    }
    cout << arr[n];
}