import sys
from itertools import combinations
from functools import reduce 

n, m = map(int, sys.stdin.readline().strip().split())
primeArr = list(map(int, sys.stdin.readline().strip().split()))


# list(combinations(items, 2))
# [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '4'), ('3', '5'), ('4', '5')]

# result2 = reduce((lambda x, y: x * y), list2)

answer = 0
flag = 1
for  i in range(n):
    combs = list(combinations(primeArr, i+1))
    for li in combs:
        value = reduce((lambda x, y: x*y), li)
        temp = int(m/value)
        answer += flag*temp
    flag *= -1

print(answer)