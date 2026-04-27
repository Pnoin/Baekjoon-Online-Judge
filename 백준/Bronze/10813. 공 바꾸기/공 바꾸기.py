n,m=map(int,input().split())
a=[]
for i in range(n+1):
    a.append(i)
for i in range(m):
    x,y=map(int,input().split())
    a[x],a[y]=a[y],a[x]
for i in range(1,n+1):
    print(a[i],end=" ")