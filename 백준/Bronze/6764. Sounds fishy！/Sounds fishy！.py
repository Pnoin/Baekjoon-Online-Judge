arr=[]
total=0
for i in range(4):
    a=int(input())
    arr.append(a)
for i in range(3):
    if(arr[i+1]>arr[i]):
        total+=1
    elif(arr[i+1]<arr[i]):
        total-=1
if(len(set(arr))==1): 
    print("Fish At Constant Depth")
elif(total==3):
    print("Fish Rising")
elif(total==-3):    
    print("Fish Diving")
else:
    print("No Fish")