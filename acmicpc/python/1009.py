import sys
# sys.stdin = open('input.txt','r')

n = int(sys.stdin.readline())
for _ in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    a %= 10
    mods = [a]
    a = (a*mods[0])%10
    while a != mods[0]:
        mods.append(a)
        a = (a*mods[0])%10
    answer = mods[(b-1)%len(mods)]
    if answer == 0:
        answer = 10
    print(answer)
