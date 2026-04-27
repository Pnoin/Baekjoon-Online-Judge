a=list(map(int,input().split()))
a.sort()
total=0
total+=a[2]-a[1]
total+=a[2]-a[0]
print(total)