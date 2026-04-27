#include <cstdio>

int main()
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a+b+c==180)
  {
    if(a!=b and b!=c and c!=a)
    {
      printf("Scalene");
    }
    else
    {
      if(a==b and b==c and c==a)
      {
        printf("Equilateral");
      }
      else
      {
        printf("Isosceles");
      }
    }
  }
  else
  {
    printf("Error");
  }
}
