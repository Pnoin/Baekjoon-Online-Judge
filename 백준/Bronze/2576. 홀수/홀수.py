total=0
odd=[]
for i in range(7):
    n=int(input())
    if(n%2==1):
        total+=n
        odd.append(n)
odd.sort()
if(total==0):
    print(-1)
else:
    print(total)
    print(odd[0])