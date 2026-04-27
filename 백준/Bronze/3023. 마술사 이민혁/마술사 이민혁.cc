#include <iostream>
#include <string>
using namespace std;

int main(){
  int r,c,a,b,count;
  cin >> r >> c;
  char arr[105][105]={};
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      cin >> arr[i][j];
    }
  }
  cin >> b >> a;
  for(int i=1; i<=r; i++){
    count=c;
    for(int j=c+1; j<=c+c; j++){
      arr[i][j]=arr[i][count];
      count--;
    }
  }
  count=r;
  for(int i=r+1; i<=r+r; i++){
    for(int j=1; j<=c+c; j++){
      arr[i][j]=arr[count][j];
    }
    count--;
  }
  if(arr[b][a]=='.'){
    arr[b][a]='#';
  }
  else if(arr[b][a]=='#'){
    arr[b][a]='.';
  }
  for(int i=1; i<=r+r; i++){
    for(int j=1; j<=c+c; j++){
      cout << arr[i][j];
    }
    cout << "\n";
  }
}