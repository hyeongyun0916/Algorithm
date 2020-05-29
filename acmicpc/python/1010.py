import sys
# sys.stdin = open('input.txt','r')

facts = [0]*31
facts[0] = facts[1] = 1
for i in range(1, 31):
    facts[i] = i*facts[i-1]

# print(facts)

n = int(sys.stdin.readline())
for _ in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    print(int(facts[b]/(facts[b-a]*facts[a])))