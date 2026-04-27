for i in range(int(input())):
    a=list(map(str,input().split()))
    print("Case ",end="")
    print('#',end="")
    print(i+1,end="")
    print(": ",end="")
    for j in reversed(a):
        print(j,end=" ")
    print("")
