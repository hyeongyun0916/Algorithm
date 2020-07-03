import sys
sys.stdin = open('input.txt', 'r')

'''
3
1
1
1
'''
n = int(sys.stdin.readline())
a = [sys.stdin.readline() for i in range(n)]
list((map(int, a)))
# 3 7
a, b = map(int, sys.stdin.readline().strip().split())
# 3 7 8
list(map(int, sys.stdin.readline().strip().split()))
i = 7
sys.stdout.write(str(i)+'\n')