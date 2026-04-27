n=int(input())
a=list(map(int,input().split()))
print((((n-1)*8)+sum(a))//24,(((n-1)*8)+sum(a))%24)