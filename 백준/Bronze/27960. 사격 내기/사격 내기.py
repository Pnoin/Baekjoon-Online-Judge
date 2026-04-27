arr=[]
for i in range(10):
    arr.append(pow(2,i))
arr.reverse()
a,b=map(int,input().split())
cnt=[]
for i in range(10):
    cnt.append(0)
idx=0
while(True):
    if(a==0):
        break
    if(arr[idx]>a):
        idx+=1
    else:
        a-=arr[idx]
        cnt[idx]+=1
        idx+=1
idx=0
while(True):
    if(b==0):
        break
    if(arr[idx]>b):
        idx+=1
    else:
        b-=arr[idx]
        cnt[idx]+=1
        idx+=1
total=0
for i in range(10):
    if(cnt[i]==1):
        total+=arr[i]
print(total)
