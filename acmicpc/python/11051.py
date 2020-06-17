import sys

a, b = map(int, sys.stdin.readline().strip().split())
facts = [0]*1001
facts[0] = facts[1] = 1
for i in range(1, 1001):
    facts[i] = (i*facts[i-1])%10007

print((facts[a]*(pow((facts[b]*facts[a-b]),10007-2)))%10007)