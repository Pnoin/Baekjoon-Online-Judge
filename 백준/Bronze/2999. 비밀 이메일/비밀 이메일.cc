///2999
#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;                                   ///boudonuimilcbsai
  cin >> a;
  int n=a.size(),r,c,maxr=0,minc=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i>j){                      
        continue;
      }
      else{
        if(i*j==n){
          r=i;
          c=j;
          if(r>maxr){
            maxr=r;
            minc=c;
          }
        }
      }
    }
  }
  char arr[105][105]={};                           /// 2*3              0,0     0,1    0,2    1,0   1,1   1,2  2,0 
  int k=0;        
  for(int i=0; i<minc; i++){                         /// 0,1,2,3
    for(int j=0; j<maxr; j++){                       /// 0,1,2,3
      arr[j][i]=a[k];                                /// (0,0)=b, (0,1)=o, (0,2)=u... (3,3)=i
      k++;    /// 0~15
    }
  }
  for(int i=0; i<maxr; i++){      ///x축 y축 변경
    for(int j=0; j<minc; j++){  
      cout << arr[i][j];
    }
  }
}