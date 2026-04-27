n,m=map(int,input().split())
a=[]
b=[]
for i in range(n):
    s=input()
    a.append([])
    for j in range(len(s)):
        a[i].append(s[j])
        a[i].append(s[j])

for i in range(n):
    s=input()
    b.append(s)

for i in range(n):
    for j in range(m*2):
        if(a[i][j]!=b[i][j]):
            print("Not Eyfa")
            exit()
print("Eyfa")
