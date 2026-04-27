a,b=map(int,input().split())
ans=[]
n=list(map(int,input().split()))
for i in range(a-1):
    ans.append((n[i]+n[i+1])*b)
print(min(ans))