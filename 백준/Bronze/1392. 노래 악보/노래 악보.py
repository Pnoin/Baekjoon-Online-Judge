n,m=map(int,input().split())
a=[]
for i in range(n):
    a.append(int(input()))
for i in range(m):
    x=int(input())
    for j in range(n):
        if(sum(a[:j+1])>x):
            print(j+1)
            break