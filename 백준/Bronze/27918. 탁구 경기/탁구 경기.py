t=int(input())
dtotal=0
ptotal=0
ck=0
for i in range(t):
    s=input()
    if(ck==0):
        if(s=="D"):
            dtotal+=1
            if(dtotal>=ptotal+2):
                ck=1
        else:
            ptotal+=1
            if(ptotal>=dtotal+2):
                ck=1
print(dtotal,end="")
print(":",end="")
print(ptotal)
        