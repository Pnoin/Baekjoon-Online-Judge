#include <cstdio>

int main()
{
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if(a==8 or a==9)
  {
    if(d==8 or d==9)
    {
      if(b==c)
      {
        printf("ignore");
      }
      else
      {
        printf("answer");
      }
    }
    else
    {
      printf("answer");
    }
  }
  else
  {
    printf("answer");
  }
}