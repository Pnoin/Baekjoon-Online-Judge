s=int(input())
total=0
cnt=0
for i in range(1,s+1):
    total+=i
    cnt+=1
    if(total>s):
        cnt-=1
        break
print(cnt)
    