#include <cstdio>

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  if(a>0 and b>0)
  {
    printf("%d",1);
  }
  else if(a<0 and b>0)
  {
    printf("%d",2);
  }
  else if(a<0 and b<0)
  {
    printf("%d",3);
  }
  else
  {
    printf("%d",4);
  }
}