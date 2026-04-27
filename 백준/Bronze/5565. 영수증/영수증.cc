#include <cstdio>

int main()
{
  int a,b;
  scanf("%d", &a);
  for(int i=0; i<9; i++)
  {
    scanf("%d", &b);
    a=a-b;
  }
  printf("%d", a);
}