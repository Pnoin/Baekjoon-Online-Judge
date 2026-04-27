a=[]
mx=0
for i in range(5):
  s=input()
  mx=max(mx,len(s))
  a.append(s)
for i in range(5):
  if(len(a[i])<mx):
    while(True):
      if(len(a[i])==mx):
        break
      a[i]+='.'
for i in range(mx):
  for j in range(5):
    if(a[j][i]=='.'):
      print("",end="")
    else:
      print(a[j][i],end="")