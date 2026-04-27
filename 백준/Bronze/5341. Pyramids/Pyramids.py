while True:
    a=int(input())
    if(a==0):
        exit()
    total=0
    for i in range(1,a+1):
        total+=i
    print(total)