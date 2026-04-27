n=int(input())
a=list(map(int,input().split()))
total=0
temp=[]
for i in a:
    if(i%2==0):
        total+=i
    else:
        temp.append(i)
if(len(temp)>1):
    temp.sort(reverse=True)
    if(len(temp)%2==0):
        for i in range(len(temp)):
            total+=temp[i]
    else:   
        for i in range(len(temp)-1):
            total+=temp[i]
print(total)