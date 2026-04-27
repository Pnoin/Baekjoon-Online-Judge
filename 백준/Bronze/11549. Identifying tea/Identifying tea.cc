#include <cstdio>

int main()
{
  int x,y,z=0;
  scanf("%d",&x);
  for(int i=1; i<=5; i++)
  {
    scanf("%d",&y);
    if(x==y)
    {
      z=z+1;
    }
  }
  printf("%d",z);
}