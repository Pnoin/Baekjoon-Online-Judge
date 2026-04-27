import math

x,y=map(int,input().split())
r=math.ceil(math.sqrt(y))+1
arr=[0 for i in range(r+5)]
v=[]
for i in range(2,r+1):
  if(arr[i]==0):
    j=2*i
    while(True):
      if(j>r):
        break
      arr[j]=1
      j+=i
    v.append(i)
cnt=0
for i in v:
  temp=i*i
  while(True):
    if(temp>y):
      break
    if(temp>=x and temp<=y):
      cnt+=1
    temp*=i
print(cnt)
  