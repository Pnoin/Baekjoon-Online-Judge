n=int(input())
a=[]
for i in range(1,n+1):
    a.append(i)
a.reverse()
for i in a:
    print(i,end=" ")