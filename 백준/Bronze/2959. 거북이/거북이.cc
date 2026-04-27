#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int x,y,z,m;
  scanf("%d%d%d%d", &x,&y,&z,&m);
  int a[4] = {x,y,z,m};
  sort(&a[0], &a[4]);
  printf("%d", a[0]*a[2]);
}