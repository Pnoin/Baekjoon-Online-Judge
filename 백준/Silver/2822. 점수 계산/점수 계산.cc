#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int score[10]={}, copy[10]={}, total=0;
  for(int i=0; i<8; i++){
    cin >> score[i];
    copy[i]=score[i];
  }
  sort(&copy[0], &copy[8]);
  for(int i=3; i<8; i++){
    total+=copy[i];
  }
  cout << total << "\n";
  for(int i=0; i<8; i++){
    for(int j=3; j<8; j++){
      if(score[i]==copy[j]){
        cout << i+1 << ' ';
      }
    }
  }
}