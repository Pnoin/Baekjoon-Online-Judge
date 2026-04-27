a,b=map(int,input().split())
if(a+b<0 or a-b<0 or (a+b)%2):
    print(-1)
else:
    print(max((a+b)//2,a-((a+b)//2)),min((a+b)//2,a-((a+b)//2)))