a,b=map(int,input().split())
if(a>b):
  a,b=b,a
arr=[]
for i in range(a+1,b):
    arr.append(i)
print(len(arr))
for i in arr:
    print(i,end=" ")