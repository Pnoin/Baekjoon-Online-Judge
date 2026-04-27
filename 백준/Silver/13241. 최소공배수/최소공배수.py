a,b=map(int,input().split())
tempa=a
tempb=b
while (tempb):
    md=tempb
    tempb=tempa%tempb
    tempa=md
print(a*b//tempa)