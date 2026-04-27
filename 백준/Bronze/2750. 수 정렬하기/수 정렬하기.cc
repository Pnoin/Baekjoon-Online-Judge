#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int num, a[1000]; 
  scanf("%d", &num);
  for(int i=0; i<num; i++){
    scanf("%d", &a[i]);
    sort(&a[0], &a[i+1]);
  }
  for(int i=0; i<num; i++){
    printf("%d\n", a[i]);
  }
}