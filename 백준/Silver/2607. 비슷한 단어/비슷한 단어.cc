#include <iostream>
#include <string>
using namespace std;

int main(){
  int n, alpha[30]={}, total=0;
  cin >> n;
  string a[105]={};
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<a[0].size(); i++){
    alpha[a[0][i]-65]++;
  }
  for(int i=1; i<n; i++){
    int alpha2[30], cnt=0;
    copy(alpha, alpha+26, alpha2);
    for(int j=0; j<a[i].size(); j++) {
			if(alpha2[a[i][j]-65]>0) {
				alpha2[a[i][j]-65]--;
				cnt++;
			}
		}
    if(a[0].size()==a[i].size()){
      if(cnt==a[0].size() or cnt==a[0].size()-1){
        total++;
      }
    }
    else if(a[0].size()-1==a[i].size() and cnt==a[0].size()-1){
			total++;
    }
		else if(a[0].size()+1==a[i].size() and cnt==a[0].size()){
			total++;
		}
		else{
		  continue; 
		}
  }
  cout << total;
}