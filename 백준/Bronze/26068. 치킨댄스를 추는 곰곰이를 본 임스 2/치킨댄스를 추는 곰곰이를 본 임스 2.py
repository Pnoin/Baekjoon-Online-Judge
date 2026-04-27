n=int(input())
total=0
for i in range(n):
    s=input()
    num=s[2:]
    if(int(num)<=90):
        total+=1
print(total)