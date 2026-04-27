n,m=map(int,input().split())
size=1
squ=[]
for i in range(n):
    squ.append(list(input()))
for i in range(n):
    for j in range(m):
        for k in range(min(n,m)):
            if(n>i+k and m>j+k):
                if(squ[i][j]==squ[i+k][j] and squ[i+k][j]==squ[i][j+k] and squ[i][j+k]==squ[i+k][j+k]):
                    if((k+1)*(k+1)>size):
                        size=(k+1)*(k+1)
print(size)
