n=int(input())
x=list(map(int, input().split()))
y=list(map(int, input().split()))
total=0
for i in range(n):
    total+=max(x[i],y[i])-min(x[i],y[i])
total//=2
print(total)