import sys
# sys.stdin = open('input.txt', 'r')

prime = [True]*1000001
def makePrime():
    primeLen = len(prime)
    powNumber = int(pow(primeLen,0.5))
    prime[0] = prime[1] = False
    for i in range(2, powNumber):
        for j in range(i*i, primeLen, i):
            prime[j] = False

makePrime()

a, b = map(int, sys.stdin.readline().strip().split())

answer = 0
for i in range(a,b+1):
    if prime[i]:
        print(i)
