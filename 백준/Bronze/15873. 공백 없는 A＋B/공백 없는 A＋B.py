n=int(input())
if(n<1000):
    if(n%10==0):
        print(n//100+10)
    else:
        print(n%10+n//10)
else:
    print(20)
