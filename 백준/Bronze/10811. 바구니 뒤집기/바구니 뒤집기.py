n,m=map(int,input().split())
s=[]
for i in range(n+1):
    s.append(i)
for i in range(m):
    a,b=map(int,input().split())
    temp=b
    for j in range(a,((b-a)//2)+a+1):
        s[j],s[temp]=s[temp],s[j]
        temp-=1
for i in range(1,n+1):
    print(s[i],end=" ")