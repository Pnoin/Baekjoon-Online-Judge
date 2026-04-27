n,m=map(int,input().split())
for i in range(n):
    for j in range(1,m+1):
        if(j==m):
            print((i*m)+j)
        else:
            print((i*m)+j,end=" ")
