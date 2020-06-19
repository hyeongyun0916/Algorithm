import sys
# sys.stdin = open('input.txt', 'r')

n = sys.stdin.readline()
arr = sorted(list(map(int, sys.stdin.readline().strip().split())))

temp = 0
answer = 0
sumValue = 0
for a in arr:
    temp = a + sumValue
    answer += temp
    sumValue += a

print(answer)