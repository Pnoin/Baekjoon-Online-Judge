n=int(input())
cnt1=0
cnt0=0
for i in range(n):
    a=int(input())
    if(a==1):
        cnt1+=1
    else:
        cnt0+=1
if(cnt1>cnt0):
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")
