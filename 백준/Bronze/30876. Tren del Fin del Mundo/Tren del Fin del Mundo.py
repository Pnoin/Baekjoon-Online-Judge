n=int(input())
arr=[]
brr=[]
mn=100000
for i in range(n):
    a,b=map(int,input().split())
    arr.append(a)
    brr.append(b)
    mn=min(mn,b)
for i in range(n):
    if(brr[i]==mn):
        print(arr[i], brr[i])
        exit()
    