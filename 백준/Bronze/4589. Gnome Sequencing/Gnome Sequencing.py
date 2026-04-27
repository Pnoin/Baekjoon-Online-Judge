n=int(input())
print("Gnomes:")
for i in range(n):
    arr=[]
    a,b,c=list(map(int,input().split()))
    arr.append(a)
    arr.append(b)
    arr.append(c)
    if(sorted(arr, reverse=True) == arr or sorted(arr, reverse=False) == arr):
        print("Ordered")
    else:
        print("Unordered")