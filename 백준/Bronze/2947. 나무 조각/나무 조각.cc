#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int a[5]={},count=0;
  for(int i=0; i<5; i++){
    scanf("%d", &a[i]);
  }
  while (true){
    if(a[0]<a[1] and a[1]<a[2] and a[2]<a[3] and a[3]<a[4]){
      break;
    }
    else{
      if(count==4){
        count=0;
      }
      if(a[count]>a[count+1]){
        swap(a[count],a[count+1]);
        for(int i=0; i<5; i++){
          printf("%d ", a[i]);
        }
        printf("\n");
      }
      count++;
    }
  }
}