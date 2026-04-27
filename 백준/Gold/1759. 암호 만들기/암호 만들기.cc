#include <iostream>
#include <algorithm>
using namespace std;

char alp[30]={}, arr[20]={};
int l,c;

int vowel(char q){
  if(q=='a' or q=='e' or q=='i' or q=='o' or q=='u'){
    return 1;
  }
  else{
    return 0;
  }
}

void solve(int cur, int start){
  if(cur==l){
    int zero=0, one=0;
    for(int i=0; i<l; i++){
      if(vowel(arr[i])==1){
        one++;
      }
      else{
        zero++;
      }
    }
    if(one>=1 and zero>=2){
      for(int i=0; i<l; i++){
        cout << arr[i];
      }
      cout << "\n";
      return;
    }
    else{
      return;
    }
  }
  for(int i=start; i<c; i++){
    arr[cur]=alp[i];
    solve(cur+1, i+1);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> l >> c;
  for(int i=0; i<c; i++){
    cin >> alp[i];
  }
  sort(&alp[0], &alp[c]);
  solve(0,0);
}