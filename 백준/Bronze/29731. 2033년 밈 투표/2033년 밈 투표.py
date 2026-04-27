a1=["Never", "gonna", "give","you","up"]
a2=["Never", "gonna", "let", "you", "down"]
a3=["Never", "gonna", "run", "around", "and", "desert", "you"]
a4=["Never", "gonna", "make", "you", "cry"]
a5=["Never", "gonna", "say", "goodbye"]
a6=["Never", "gonna", "tell", "a", "lie", "and", "hurt", "you"]
a7=["Never", "gonna", "stop"]

n=int(input())
cnt=0
for i in range(n):
    s=list(map(str,input().split()))
    temp=0
    if(len(s)==len(a1)):
        for j in range(len(s)):
            if(s[j]==a1[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a2)):
        for j in range(len(s)):
            if(s[j]==a2[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a3)):
        for j in range(len(s)):
            if(s[j]==a3[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a4)):
        for j in range(len(s)):
            if(s[j]==a4[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a5)):
        for j in range(len(s)):
            if(s[j]==a5[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a6)):
        for j in range(len(s)):
            if(s[j]==a6[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
    temp=0
    if(len(s)==len(a7)):
        for j in range(len(s)):
            if(s[j]==a7[j]):
                temp+=1
    if(temp==len(s)):
        cnt+=1
    
if(cnt==n):
    print("No")
else:
    print("Yes")