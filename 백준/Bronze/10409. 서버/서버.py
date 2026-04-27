n,m=map(int,input().split())
a=list(map(int,input().split()))
total=0
cnt=0
for i in a:
    total+=i
    if(total<=m):
        cnt+=1
print(cnt)
        