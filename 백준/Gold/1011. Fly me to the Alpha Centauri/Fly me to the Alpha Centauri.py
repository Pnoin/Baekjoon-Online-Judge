t = int(input())

for i in range (t):
  x,y=map(int,input().split())
  dis=y-x
  inc=1
  total=0
  while total<dis:
    total+=inc*2
    inc+=1
  inc-=1
  if total-inc >= dis:
    total=inc*2-1
  else:
    total=inc*2
  print(total)