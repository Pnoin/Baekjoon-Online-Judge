import sys
from decimal import *
input = sys.stdin.readline
getcontext().prec = 50
pi = Decimal('3.14159265358979323846264338327950288419716939937510')
a,b,c = map(Decimal,map(int,input().split()))

#사인 함수 매클로린 급수 https://python.flowdas.com/library/decimal.html
def Macsin(x):
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

#이분탐색 코드 https://www.acmicpc.net/source/42946056 본인이 풀었던 14786번 C++ 코드 파이썬으로 변환
eps=Decimal('0.0000000000000000000001')
mn=Decimal('0')
mx=Decimal('250000')
tw=Decimal('2')
med=(mx+mn)/tw
while((mx-mn)>eps):
    med=(mx+mn)/2
    temp=med%(2*pi) 
    if((a * med) + (b * Macsin(temp)) > c):
        mx=med
    elif((a * med) + (b * Macsin(temp)) < c):
        mn=med

print(round(med,6))
