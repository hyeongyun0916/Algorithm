import sys
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())
arr = [sys.stdin.readline().strip() for i in range(n)]

maxLength = min(n,m)

for length in range(maxLength,0,-1):
    for i in range(n-length+1):
        for j in range(m-length+1):
            if arr[i][j] == arr[i+length-1][j] == arr[i][j+length-1] == arr[i+length-1][j+length-1]:
                print(length*length)
                sys.exit()