n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    totalx=1
    totaly=1
    totalxy=1
    for j in range(1,x+1):
        totalx*=j
    for j in range(1,y+1):
        totaly*=j
    for j in range(1,y-x+1):
        totalxy*=j
    ans=totaly//(totalx*totalxy)
    print(ans)