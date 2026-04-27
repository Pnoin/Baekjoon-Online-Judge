#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int n,prime[1000005]={};
  scanf("%d", &n);
  if(n<8){
    printf("%d", -1);
  }
  else{
    if(n%2==0){
      printf("%d %d ",2,2);
      n=n-4;
    }
    else if(n%2!=0){
      printf("%d %d ",2,3);
      n=n-5;
    }
    for (int i=2; i<=n; i++){
      prime[i]=i;
    }
    for (int i=2; i<=sqrt(n); i++){
      if (prime[i]==0){
        continue;
      }
      for (int j=i*i; j<=n; j+=i){
        prime[j]=0;
      }
    }
    for(int i=2; i<=n; i++){
      for(int j=2; j<=n; j++){
        if(prime[i]!=0 and prime[j]!=0){
          if(prime[i]+prime[j]==n){
            printf("%d %d",prime[i],prime[j]);
            return 0;
          }
        }
      }
    }
  }
}