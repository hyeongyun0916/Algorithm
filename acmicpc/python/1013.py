import re
import sys
# sys.stdin = open('input.txt', 'r')

regex = re.compile('(100+1+|01)+')
n = int(sys.stdin.readline())
for i in range(n):
    print('YES' if re.fullmatch('(100+1+|01)+', sys.stdin.readline().strip()) else 'NO')