total=0
n=int(input())
a=list(map(int,input().split()))
for i in a:
    if(i<=n):
        total+=i
    else:
        total+=n
print(total)