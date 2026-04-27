import math

def stardust(bas,combo, skill,si,c):
    return bas*(100+(combo*c))*(100+(skill*si))//10000

combo_cnt=0
total=0
tired=0
n,k,c,r=map(int,input().split())
base=list(map(int,input().split()))
s=list(map(int,input().split()))
p=list(map(int,input().split()))
prefix_sum=[]
for i in range(100005):
    prefix_sum.append(0)
for i in range(n):
    num=int(input())
    if(num==0):
        tired-=r
        if(tired<0):
            tired=0
        combo_cnt=0
        continue
    tired+=p[num-1]
    if(tired>100):
        print(-1)
        exit()
    #print(stardust(base[num-1],combo_cnt,prefix_sum[num],s[num-1],c))
    total+=stardust(base[num-1],combo_cnt,prefix_sum[num],s[num-1],c)
    combo_cnt+=1
    prefix_sum[num]+=1
print(total)