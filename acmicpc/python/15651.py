import sys, itertools
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())
# n, m = 4, 2

# temp = itertools.combinations(range(n), m)
for temp in itertools.product(range(1, n+1), repeat=m):
    print(' '.join(map(str,temp)))