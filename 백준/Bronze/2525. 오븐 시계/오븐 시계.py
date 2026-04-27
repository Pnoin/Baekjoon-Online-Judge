a,b=map(int,input().split())
n=int(input())
if(b+(n%60)>=60):
    print((1+a+(n//60))%24,b+(n%60)-60)
else:
    print((a+(n//60))%24,b+(n%60))