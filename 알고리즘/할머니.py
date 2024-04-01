import math

def H(n):
    result = 1.0  # H(1) = 1로 시작
    for i in range(2, n + 1):  # 2부터 n까지 반복
        result = (i * result + 1) / i
    return result

def Euler_const(n): 
    return math.log(n) - H(n)

for i in range(1000000, 10000000, 1000000):
    print(Euler_const(i))
