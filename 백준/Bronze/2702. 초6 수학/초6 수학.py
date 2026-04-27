def Euclidean(a, b):
    while b != 0:
        [a, b] = [b, a%b]
    return a

t=int(input())
for i in range(t):
    x,y=map(int,input().split())
    gcd=Euclidean(x,y)
    lcm=Euclidean(x,y)*(x//Euclidean(x,y))*(y//Euclidean(x,y))
    print(lcm,end=" ")
    print(gcd)