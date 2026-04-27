#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;
  cin >> a;
  int sum=0,cnt=0;
  for(int i=0; i<a.size(); i++){
    if(65<=a[i] and a[i]<=90){
      sum+=(a[i]-38);
    }
    else if(97<=a[i] and a[i]<=122){
      sum+=(a[i]-96);
    }
  }
  if(sum==1){
    cout << "It is a prime word.";
  }
  else{
    for(int i=1; i<=sum; i++){
      if(sum%i==0){
        cnt++;
      }
    }
    if(cnt==2){
      cout << "It is a prime word.";
    }
    else{
      cout << "It is not a prime word.";
    }
  }
}