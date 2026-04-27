color=['black','brown','red','orange','yellow','green','blue','violet','grey','white']
a=input()
b=input()
c=input()
A=0
B=0
C=0
for i in range(10):
    if(a==color[i]):
        A=i
    if(b==color[i]):
        B=i
    if(c==color[i]):
        C=i
print(int(str(A)+str(B))*(10**C))