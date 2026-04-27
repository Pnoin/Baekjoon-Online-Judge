t=int(input())
for i in range(t):
  a=list(map(int,input().split()))
  av=(sum(a)-a[0])/(a[0])
  cnt=0
  for j in range(1,a[0]+1):
    if(a[j]>av):
      cnt+=1
  print(round((cnt/a[0])*100,3),end="")
  print("%")