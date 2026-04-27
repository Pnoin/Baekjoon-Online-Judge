a=list(map(int, input().split()))
a.sort()
x=a[1]-a[0]
y=a[2]-a[1]
if(x==y):
    print(a[2]*2-a[1])
elif(x>y):
    print(a[1]*2-a[2])

else:
    print(a[1]*2-a[0])