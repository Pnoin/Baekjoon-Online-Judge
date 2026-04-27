t=int(input())
for i in range(t):
    p=int(input())
    for j in range(p):
        a=list(map(int,input().split()))
        print(a[0]+a[1],a[0]*a[1])