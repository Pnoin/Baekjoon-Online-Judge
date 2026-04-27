#include <cstdio>

int main()
{
  int x,a,b,q=0,w=0;
  scanf("%d", &x);
  for(int i=1; i<=x; i++)
  {
    scanf("%d %d",&a,&b);
    if(a>b)
    {
      q=q+1;
    }
    else if(a<b)
    {
      w=w+1;
    }
  }
  printf("%d %d", q,w);
}