def gcd(x, y):
  while(y!=0):
    x,y=y,x%y
  return x

n=int(input())
for i in range(n):
  a,b=map(int,input().split())
  print((a*b)//gcd(a,b))