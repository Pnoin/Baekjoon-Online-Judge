#include <iostream>
#include <string>
using namespace std;

int main(){
  char arr[35][35]={};
  int ap=0,bp=0,check=0;
  string a,b;
  cin >> a >> b;
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      if(check==1){
        continue;
      }
      if(a[i]==b[j]){
        ap=i;
        bp=j;
        check=1;
      }
    }
  }
  for(int i=0; i<a.size(); i++){                ///3        [j][i]
    for(int j=0; j<b.size(); j++){           ///4
      arr[i][j]='.';
    }
  }
  for(int i=0; i<a.size(); i++){
    arr[i][bp]=a[i];
  }
  for(int i=0; i<b.size(); i++){
    arr[ap][i]=b[i];
  }
  for(int i=0; i<b.size(); i++){                ///3        [j][i]
    for(int j=0; j<a.size(); j++){           ///4
      cout << arr[j][i];
    }
    cout<<"\n";
  }
}