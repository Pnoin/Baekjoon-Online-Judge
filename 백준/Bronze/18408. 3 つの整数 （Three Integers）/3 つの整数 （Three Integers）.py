a=list(map(int,input().split()))
total1=0
total2=0
for i in a:
    if(i==1):
        total1+=1
    else:
        total2+=1
if(total1>total2):
    print(1)
else:
    print(2)
