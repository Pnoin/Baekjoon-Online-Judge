n=int(input())
a=0
b=1
ans=0
if(n==1):
    print(1)
    exit()
for i in range(2,n+1):
    ans=a+b
    a=b
    b=ans
print(ans)