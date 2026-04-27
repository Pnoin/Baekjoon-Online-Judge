a,b,c=map(int,input().split())
if(a%(c-b)):
    print(a//(c-b)+1)
else:
    print(a//(c-b))