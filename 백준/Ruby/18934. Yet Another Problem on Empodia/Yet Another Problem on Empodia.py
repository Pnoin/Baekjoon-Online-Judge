#https://www.acmicpc.net/source/77073086
#overflow 에러 때문에 python으로 변경

n,md=map(int,input().split())
arr=[0]*(n+5) 
arr[0]=1
arr[1]=1
arr[2]=3
arr[3]=12
arr[4]=52
arr[5]=240

for i in range(1,n+1):
    if(i<=6):
        print(arr[i-1])
        continue
    num=(((i-1)*(i-2)*(2079652*i*i-10492117*i+10802220)*arr[i-2]-6*(i-2)*(98404*i*i*i-611787*i*i+893503*i+124240)*arr[i-3]-2*(-1206916*i*i*i*i+13262653*i*i*i-52943063*i*i+90096428*i-54243072)*arr[i-4]-(-16564*i*i*i*i+1171171*i*i*i-12487565*i*i+47878166*i-62441016)*arr[i-5]-3*(3*i-14)*(i-5)*(388*i-1861)*(3*i-16)*arr[i-6]))
    den=(177*i*(i-1)*(i-2)*(1884*i-6797))
    arr[i-1]=(num//den)
    print(arr[i-1]%md)

