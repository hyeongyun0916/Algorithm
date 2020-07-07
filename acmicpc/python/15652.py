import sys, itertools
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())
# n, m = 3, 3

# temp = itertools.combinations(range(n), m)
for temp in itertools.combinations_with_replacement(range(1, n+1), m):
    print(' '.join(map(str,temp)))