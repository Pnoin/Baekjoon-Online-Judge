n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    temp=0
    for j in range(1,x+1):
        for k in range(j+1,x):
            if((j*j+k*k+y)%(j*k)==0):
                temp+=1
    print(temp)
