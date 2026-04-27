n=int(input())
total=0
a=list(map(int,input().split()))
for i in range(n) :
  if(a[i]!=i+1):
    total+=1
print(total)