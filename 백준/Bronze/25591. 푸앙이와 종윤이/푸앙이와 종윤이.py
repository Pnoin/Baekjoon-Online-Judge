a,b=map(int,input().split())
x=100-a
y=100-b
print(x,y,100-x-y,x*y,(x*y)//100,(x*y)%100)
print((100-x-y)+(x*y)//100,(x*y)%100)