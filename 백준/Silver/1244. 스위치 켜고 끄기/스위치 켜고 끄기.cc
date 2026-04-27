#include <iostream>
using namespace std;

int main(){
  int n, s[105]={}; 
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> s[i];
  }
  int a, sex, num;
  cin >> a;
  for(int i=1; i<=a; i++){
    cin >> sex >> num;
    if(sex==1){
      for(int j=1; j<=n; j++){
        if(j%num==0){
          if(s[j]==1){
            s[j]=0;
          }
          else if(s[j]==0){
            s[j]=1;
          }
        }
      }
    }
    else if(sex==2){
      int cnt=1;
      if(s[num]==0){
        s[num]=1;
      }
      else if(s[num]==1){
        s[num]=0;
      }
      while(true){
        if(num-cnt>0 and num+cnt<=n){
          if(s[num+cnt]==s[num-cnt]){
            if(s[num+cnt]==0){
              s[num+cnt]=1;
            }
            else if(s[num+cnt]==1){
              s[num+cnt]=0;
            }
            if(s[num-cnt]==0){
              s[num-cnt]=1;
            }
            else if(s[num-cnt]==1){
              s[num-cnt]=0;
            }
            cnt++;
          }
          else if(s[num+cnt]!=s[num-cnt]){
            break;
          }
        }
        else{
          break;
        }
      }
    }
  }
  for(int i=1; i<=n; i++){
    cout << s[i] << ' ';
    if(i%20==0){
      cout << "\n";
    }
  }
}