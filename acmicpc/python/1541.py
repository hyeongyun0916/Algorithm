import sys
# sys.stdin = open('input.txt', 'r')

s = input()

index = s.find('-')
result = 0
if index == -1:
	result = sum(list(map(int, s.split('+'))))
else:
	a = sum(list(map(int, s[:index].split('+'))))
	b = sum(list(map(int, s[index+1:].replace('+','-').split('-'))))
	result = a - b

print(result)