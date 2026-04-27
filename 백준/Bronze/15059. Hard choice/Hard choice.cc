    #include <cstdio>

int main()
{
  int a,b,c,A,B,C,ad=0,bd=0,cd=0;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &A, &B, &C);
  if(a<A)
  {
    ad=A-a;
  }
  if(b<B)
  {
    bd=B-b;
  }
  if(c<C)
  {
    cd=C-c;
  }
  printf("%d", ad+bd+cd);
}