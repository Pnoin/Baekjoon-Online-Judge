#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;
  cin >> a;
  int joi=0, ioi=0;
  for(int i=0; i<a.size(); i++){
    if(a[i-2]=='J' and a[i-1]=='O' and a[i]=='I'){
      joi=joi+1;
    }
    else if(a[i-2]=='I' and a[i-1]=='O' and a[i]=='I'){
      ioi=ioi+1;
    }
  }
  printf("%d\n%d",joi,ioi);
}