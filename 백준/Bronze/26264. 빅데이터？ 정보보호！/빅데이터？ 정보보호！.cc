#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,bn=0,sn=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='s'){
            sn++;
        }
        else if(s[i]=='b'){
            bn++;
        }
    }
    if(bn>sn){
        cout << "bigdata?";
    }
    else if(bn<sn){
        cout <<"security!";
    }
    else{
        cout <<"bigdata? security!";
    }
}