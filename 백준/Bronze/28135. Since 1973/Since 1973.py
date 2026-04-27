n=input()
num=int(n)
a=[]
a.append(0)
for i in range(1,num+1):
    temp=str(i)
    a.append(i)
    for j in range(len(temp)-1):
        if(temp[j]=='5' and temp[j+1]=='0'):
            a.append(i)
            break
for i in range(1, len(a)+1):
    if(a[i]==num):
        print(i)
        exit()