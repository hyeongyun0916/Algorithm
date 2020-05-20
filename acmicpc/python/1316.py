import sys
# sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
answer = n
for t in range(n):
    alphabet = [False]*26
    s = input()
    i = 0
    while i < len(s):
        while i+1 < len(s) and s[i] == s[i+1]:
            i += 1
        if alphabet[ord(s[i])-ord('a')]:
            answer -= 1
            break
        alphabet[ord(s[i])-ord('a')] = True
        i += 1
print(answer)
