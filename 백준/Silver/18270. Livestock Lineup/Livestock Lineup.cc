#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, total=0;
string cow[10]={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"}, x[10]={}, y[10]={}, arr[10]={};

int main(){
  cin >> n;
  string must, be, milked, beside;
  for(int i=0; i<n; i++){
    cin >> x[i] >> must >> be >> milked >> beside >> y[i];
  }
  sort(&cow[0], &cow[8]);
  do{
    int total=0;
    for(int i=0; i<n; i++){
      for(int j=0; j<7; j++){
        if(cow[j]==x[i] and cow[j+1]==y[i]){
          total++;
        }
        if(cow[j]==y[i] and cow[j+1]==x[i]){
          total++;
        }
      }
    }
    if(total==n){
      for(int i=0; i<8; i++){
        cout << cow[i] << "\n";
      }
      return 0;
    }
  }while(next_permutation(&cow[0], &cow[8]));
}