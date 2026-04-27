#include <iostream>
#include <string>
using namespace std;

int main(){
    int total=0;
    for(int i=0; i<4; i++){
        string s;
        int a;
        cin >> s >> a;
        if(s=="Es"){
            total+=21*a;
        }
        else{
            total+=17*a;
        }
    }
    cout << total;
}
