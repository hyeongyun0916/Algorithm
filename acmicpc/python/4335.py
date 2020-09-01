import sys
# sys.stdin = open('input.txt', 'r')


n = int(sys.stdin.readline())
while n != 0:
    s = ''
    minValue = 0
    maxValue = 11
    while s != 'right on\n':
        s = sys.stdin.readline()
        if s == 'too high\n':
            maxValue = min(maxValue, n)
        elif s == 'too low\n':
            minValue = max(minValue, n)
        else:
            if minValue < n < maxValue:
                print('Stan may be honest')
            else:
                print('Stan is dishonest')
        n = int(sys.stdin.readline())