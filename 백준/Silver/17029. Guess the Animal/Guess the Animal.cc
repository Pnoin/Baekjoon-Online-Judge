#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n, total=0;
  cin >> n;
  vector <string> f[105]={};
  for(int i=0; i<n; i++){
    string animal;
    int num;
    cin >> animal >> num;
    for(int j=0; j<num; j++){
      string q;
      cin >> q;
      f[i].push_back(q);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int cnt=0;
      for(int k=0; k<f[i].size(); k++){
        for(int l=0; l<f[j].size(); l++){
          if(f[i][k]==f[j][l]){
            cnt++;
          }
        }
      }
      if(cnt>total){
        total=cnt;
      }
    }
  }
  cout << total+1;
}