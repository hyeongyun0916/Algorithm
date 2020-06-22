import sys

modValue = 1000000007
# maxN = 4000000

def fastPow(x, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return (fastPow(x, n//2) ** 2) % modValue
    else:
        return (fastPow(x, n//2) ** 2 * x) % modValue

a, b = map(int, sys.stdin.readline().strip().split())
# a, b = 5, 2
facts = [0]*(a+1)
facts[0] = facts[1] = 1
for i in range(1, a+1):
    facts[i] = (i*facts[i-1])%modValue


print((facts[a]*fastPow((facts[b]*facts[a-b])%modValue,modValue-2))%modValue)