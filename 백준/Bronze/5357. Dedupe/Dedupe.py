n=int(input())
for i in range(n):
    s=input()
    prv=s[0]
    print(s[0],end="")
    for j in range(1,len(s)):
        if(s[j]!=prv):
            prv=s[j]
            print(s[j],end="")
    print("")
            