n=int(input())
a=list(map(int,input().split()))
od=0
ev=0
for i in a:
    if(i%2):
        od+=1
    else:
        ev+=1
if(ev>od):
    print("Happy")
else:
    print("Sad")