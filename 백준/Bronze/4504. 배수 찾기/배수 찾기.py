n=int(input())
while(True):
    m=int(input())
    if(m==0):
        break
    if(m%n==0):
        print(m,end=" ")
        print("is a multiple of ",end="")
        print(n,end="")
        print('.')
    else:
        print(m,end=" ")
        print("is NOT a multiple of ",end="")
        print(n,end="")
        print('.')