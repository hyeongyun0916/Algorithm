import sys
# sys.stdin = open('input.txt', 'r')


n = int(sys.stdin.readline())
answer = 0
change = 1000-n
answer += change//500
change %= 500
answer += change//100
change %= 100
answer += change//50
change %= 50
answer += change//10
change %= 10
answer += change//5
change %= 5
answer += change

print(answer)