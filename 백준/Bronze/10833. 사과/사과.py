t=int(input())
total=0
for i in range(t):
    a,b=map(int,input().split())
    if(a>b):
        total+=b
    else:
        total+=(b%a)
print(total)