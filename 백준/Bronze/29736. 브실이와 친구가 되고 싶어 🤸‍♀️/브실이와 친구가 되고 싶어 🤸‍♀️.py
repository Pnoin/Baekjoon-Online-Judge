a,b=map(int,input().split())
k,x=map(int,input().split())
mx=k+x
mn=k-x
if(mx<a or mn>b):
    print("IMPOSSIBLE")
    exit()
if(mx>b):
    mx=b
if(mn<a):
    mn=a
print(mx-mn+1)