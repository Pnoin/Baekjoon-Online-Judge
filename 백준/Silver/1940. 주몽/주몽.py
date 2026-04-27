n=int(input())
m=int(input())
a=list(map(int,input().split()))
cnt=0
for i in range(len(a)):
    for j in range(i+1,len(a)):
        if(a[i]+a[j]==m):
            cnt+=1
print(cnt)