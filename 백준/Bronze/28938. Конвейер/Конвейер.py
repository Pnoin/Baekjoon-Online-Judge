n=int(input())
a=list(map(int,input().split()))
if(sum(a)>0):
    print("Right")
elif(sum(a)==0):
    print("Stay")
else:
    print("Left")