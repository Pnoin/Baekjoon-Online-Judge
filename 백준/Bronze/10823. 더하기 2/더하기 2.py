arr=""
while(True):
    try:
        arr+=str(input())
    except:
        break
print(sum(map(int,arr.split(','))))