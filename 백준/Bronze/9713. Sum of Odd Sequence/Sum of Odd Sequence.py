t=int(input())
for i in range(t):
    n=int(input())
    total=0
    for j in range(1,n+1):
        if(j%2==1):
            total+=j
    print(total)