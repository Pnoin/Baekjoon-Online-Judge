cnt=0
while(True):
    try:
        a,b,c,d,e=map(str,input().split())
        cnt+=1
    except EOFError:
        break
print(cnt)