n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    cnt=0
    for j in range(a,b+1):
        s=str(j)
        cnt+=s.count('0')
    print(cnt)