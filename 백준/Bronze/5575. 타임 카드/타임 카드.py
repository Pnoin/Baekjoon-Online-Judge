for i in range(3):
    a=list(map(int,input().split()))
    fin=((a[3]*3600)+(a[4]*60)+a[5])-((a[0]*3600)+(a[1]*60)+a[2])
    print(fin//3600, (fin%3600)//60, (fin%3600)%60)