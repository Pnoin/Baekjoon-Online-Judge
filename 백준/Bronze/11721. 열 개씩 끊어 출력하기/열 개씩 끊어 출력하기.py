s=str(input())
cnt=0
for i in range(len(s)):
    cnt+=1
    if(cnt==11):
        print("")
        cnt=1
    print(s[i],end='')