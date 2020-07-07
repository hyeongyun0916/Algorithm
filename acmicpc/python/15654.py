import sys, itertools
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())
# n, m = 3, 3
arr = list(map(int, sys.stdin.readline().strip().split()))
arr.sort()
# temp = itertools.combinations(range(n), m)
for temp in itertools.permutations(arr, m):
    print(' '.join(map(str,temp)))