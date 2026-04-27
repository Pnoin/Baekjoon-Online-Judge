n=int(input())
total=0
for i in range(n) :
    a,b,c=map(int,input().split())
    if(a==b+c):
        total=max(a*(b+c)*2,total)
    else:
        total=max(a*(b+c),total)
print(total)