for i in range(int(input())):
    n=int(input())
    print(n,end=" ")
    cnt=0
    for j in range(1,n+1):
        if(n%j==0):
            cnt+=1
    print(cnt)