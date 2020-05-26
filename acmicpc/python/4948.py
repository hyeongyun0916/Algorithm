import sys
# sys.stdin = open('input.txt', 'r')

prime = [True]*(123456*2+1)
def makePrime():
    primeLen = len(prime)
    powNumber = int(pow(primeLen,0.5))
    prime[0] = prime[1] = False
    for i in range(2, powNumber):
        if prime[i]:
            for j in range(i*i, primeLen, i):
                prime[j] = False

makePrime()

n = int(sys.stdin.readline())
while n != 0:
    print(prime[n+1:2*n+1].count(True))
    n = int(sys.stdin.readline())