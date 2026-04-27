n,m=map(int,input().split())
ans=0
for i in range(n):
    s=input()
    cnt=0
    for j in s:
        if(j=='O'):
            cnt+=1
    if(cnt>=m/2):
        ans+=1
print(ans)
        