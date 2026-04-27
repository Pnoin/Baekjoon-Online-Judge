n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(1,n):
    a[i]+=a[i-1]
a.sort(reverse=True)
total=0
for i in range(k):
    total+=a[i]
print(total)
