a=list(map(int, input().split()))
x,y,r=map(int, input().split())
print(a.index(x)+1 if x in a else 0)