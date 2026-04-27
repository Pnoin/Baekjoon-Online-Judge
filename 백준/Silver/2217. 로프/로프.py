n=int(input())
a=[]
for i in range(n):
  num=int(input())
  a.append(num)
a.sort()
a.reverse()
mx=0
for i in range(n):
  mx=max(mx,a[i]*(i+1))
print(mx)