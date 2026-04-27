#include <iostream>
using namespace std;

int main(){
    int n, q, cnt = 0;
    cin >> n; 
    for(int t = 0; t < 5; t++){
        cin >> q;
        if(q == n){
            cnt += 1;
        }
    }
    cout << cnt;
}