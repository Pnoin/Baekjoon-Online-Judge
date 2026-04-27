n=int(input())
a=list(map(int,input().split()))
if(n*a[0]+a[1]==n*a[2]+a[3]):
    print("Yes",n*a[0]+a[1])
else:
    print("No")