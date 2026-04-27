arr=[]
for i in range(1,1001):
    for j in range(i):
        arr.append(i)
a,b=map(int,input().split())
total=0
for i in range(a-1,b):
    total+=arr[i]
print(total)