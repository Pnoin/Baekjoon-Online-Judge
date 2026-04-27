n=int(input())
if(n%10!=0):
    print(-1)
    exit()
a=[300,60,10]
for i in a:
    print(n//i,end=' ')
    n%=i