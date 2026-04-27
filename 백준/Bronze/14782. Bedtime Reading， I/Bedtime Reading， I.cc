#include <cstdio>

int main()
{
  int i,x=0;
  scanf("%d",&i);
  for(int a=1; a<=i; a++)
  {
    if(i%a==0)
    {
      x=x+a;
    }
  }
  printf("%d",x);
}