while(True):
    a,b=map(int,input().split())
    if(a==0 and b==0):
        break
    if(a<b):
        if(b%a==0):
            print("factor")
            continue
    elif(a>b):
        if(a%b==0):
            print("multiple")
            continue
    print("neither")