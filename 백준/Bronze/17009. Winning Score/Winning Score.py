x=[]
for i in range(3):
    x.append(int(input()))
y=[]
for i in range(3):
    y.append(int(input()))
a=(x[0]*3)+(x[1]*2)+x[2]
b=(y[0]*3)+(y[1]*2)+y[2]
if(a==b):
    print("T")
elif(a>b):
    print("A")
else:
    print("B")