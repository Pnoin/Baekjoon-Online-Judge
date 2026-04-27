n=int(input())
a=list(map(int,input().split()))
mx=0
for i in range(len(a)):
    mx=max(mx,a[i]-n+i)
print(mx)
