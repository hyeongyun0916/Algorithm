import sys
# sys.stdin = open('input.txt', 'r')

prime = [True]*1001

def makePrime():
    prime[0] = prime[1] = False
    for i in range(2, 31):
        for j in range(i+i, 1001, i):
            prime[j] = False

makePrime()

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))

answer = 0
for a in arr:
    if prime[a]:
        answer += 1

print(answer)