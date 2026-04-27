#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;

vector <char> v1;
vector <char> v2;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  int numx=0;
  cin >> s;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='x'){
      numx++;
    }
  }
  if(numx==0){
    int p=stoi(s);
    if(p==0){
        cout << "W";
        return 0;
    }
    if(p==1){
      cout << "x+W";
    }
    else if(p==-1){
      cout << "-x+W";
    }
    else{
      cout << p << "x+W";
    }
    return 0;
  }
  for(int i=0; i<s.size(); i++){
    if(s[i]=='x'){
      for(int j=0; j<i; j++){
        v1.push_back(s[j]);
      }
    }
    else if(i>0 and s[i-1]=='+'){
      for(int j=i; j<s.size(); j++){
        v2.push_back(s[j]);
      }
      break;
    }
    else if(i>0 and s[i]=='-'){
      for(int j=i; j<s.size(); j++){
        v2.push_back(s[j]);
      }
      break;
    }
  }
  string a(v1.begin(),v1.end());
  string b(v2.begin(),v2.end());
  int x=stoi(a), y=0;
  if(b.size()!=0){
    y=stoi(b);
  }
  int just=0;
  if(x>0){
    if(x/2!=1){
      cout << x/2 << "xx";
    }
    else if(x/2==1){
      cout << "xx";
    }
  }
  else{
    if(x/2!=-1){
      cout << x/2 << "xx";
    }
    else if(x/2==-1){
      cout << "-xx";
    }
  }
  if(y>0){
    cout << '+';
    if(y!=1){
      cout << y << 'x';
    }
    else{
      cout << 'x';
    }
  }
  else if(y==0){
    just=1;
  }
  else{
    if(y==-1){
      cout << "-x";
    }
    else{
      cout << y << 'x';
    }
  }
  cout << "+W";
}