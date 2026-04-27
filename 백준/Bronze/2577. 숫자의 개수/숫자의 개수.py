a=int(input())
b=int(input())
c=int(input())
p=a*b*c
q=[0,0,0,0,0,0,0,0,0,0]
while(p>0):
    q[p%10]+=1
    p=p//10
for i in range(10):
    print(q[i])
