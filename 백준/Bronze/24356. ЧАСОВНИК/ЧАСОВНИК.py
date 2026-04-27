a,b,c,d=map(int,input().split())
if ((c-a)*60+(d-b)<0):
    print((c-a)*60+(d-b)+1440, ((c-a)*60+(d-b)+1440)//30)
else:
    print((c-a)*60+(d-b), ((c-a)*60+(d-b))//30)