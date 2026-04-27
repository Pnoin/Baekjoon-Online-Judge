t=int(input())
total=0
s=list(map(int,input().split()))
a,b=map(int,input().split())
for i in s:
    i-=a
    total+=1
    if(i>0):
        total+=(i//b)
        if(i%b!=0):
            total+=1
print(total)