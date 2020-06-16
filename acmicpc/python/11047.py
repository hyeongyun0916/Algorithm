import sys
# sys.stdin = open('input.txt', 'r')

n, k = map(int, sys.stdin.readline().strip().split())
coins = reversed(list((map(int, [sys.stdin.readline() for i in range(n)]))))

answer = 0

for coin in coins:
    answer += k//coin
    k %= coin

print(answer)