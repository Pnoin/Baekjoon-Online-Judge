n=int(input())
p=int(input())   
total=0
if(n>=5):
    total=max(total,500)
if(n>=10):
    total=max(total,p//10)
if(n>=15):
    total=max(total,2000)

if(n>=20):
    total=max(total,p//4)
 
if(p<=total):
    print(0)
else:
    print(p-total)