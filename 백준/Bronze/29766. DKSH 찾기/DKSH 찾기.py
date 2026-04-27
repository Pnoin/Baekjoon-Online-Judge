s=input()
total=0
for i in range(len(s)-3):
    if(s[i]=='D' and s[i+1]=='K' and s[i+2]=='S' and s[i+3]=='H'):
        total+=1
print(total)
