n,m=map(int,input().split())
chess=[]
mini=9999

for i in range(n):
    chess.append(list(input()))

for i in range(0, n-7):
    for j in range(0, m-7):
        w=0
        b=0
        for k in range(i, i+8):
            for l in range(j, j+8):
                if((k+l)%2==0):
                    if(chess[k][l]=='W'):
                        b+=1
                    else:
                        w+=1
                else:
                    if(chess[k][l]=='W'):
                        w+=1
                    else:
                        b+=1
        mini = min([mini,w,b])
print(mini)
                        
                
        
