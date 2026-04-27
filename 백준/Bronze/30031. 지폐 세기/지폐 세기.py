total=0
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    if(a==136):
        total+=1000
    elif(a==142):
        total+=5000
    elif(a==148):
        total+=10000
    else:
        total+=50000
print(total)