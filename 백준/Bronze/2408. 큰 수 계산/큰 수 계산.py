n=int(input())
s=""
for i in range(2*n-1):
    C=input()
    if(C == "/"):
        s+="//"
    else:
        s+=C
print(eval(s))