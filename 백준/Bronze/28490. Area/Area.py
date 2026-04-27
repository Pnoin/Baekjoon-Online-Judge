t=int(input())
ans=0
for i in range(t):
    a,b=map(int,input().split())
    ans=max(ans,a*b)
print(ans)