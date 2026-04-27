t=int(input())
for i in range(t):
    a=list(map(int,input().split()))
    total=0
    mn=100
    for j in a:
        if(j%2==0):
            total+=j
            mn=min(mn,j)
    print(total, mn)