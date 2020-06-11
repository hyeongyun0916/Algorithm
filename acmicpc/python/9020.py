import sys
# sys.stdin = open('input.txt', 'r')

prime = [True]*(10000*2+1)
def makePrime():
    primeLen = len(prime)
    powNumber = int(pow(primeLen,0.5))
    prime[0] = prime[1] = False
    for i in range(2, powNumber):
        for j in range(i*i, primeLen, i):
            prime[j] = False

makePrime()

t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    for j in range(int(n/2), n):
        if prime[j] and prime[n-j]:
            print(n-j, j)
            break