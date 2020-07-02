import sys, itertools
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())

# temp = itertools.combinations(range(n), m)
for temp in itertools.permutations(range(1, n+1), m):
    print(*temp)