a=[]
for i in range(6):
    a.append(input())
cnt=a.count("W")
if(cnt>=5):
    print(1)
elif(cnt>=3):
    print(2)
elif(cnt>=1):
    print(3)
else:
    print(-1)