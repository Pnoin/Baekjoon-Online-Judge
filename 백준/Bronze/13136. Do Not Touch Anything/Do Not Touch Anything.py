import math as m
a,b,c=map(int,input().split())
print(int(m.ceil(a/c)*m.ceil(b/c)))