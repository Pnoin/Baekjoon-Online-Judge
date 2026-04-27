t=int(input())
for i in range(t):
    a,b,c=map(float,input().split())
    print('$',end="")
    print("{:.2f}".format(round(a*b*c,2)))
