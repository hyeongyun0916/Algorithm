import sys 
# sys.stdin = open('input.txt', 'r')

# def findDenominator(d):
#     dc = len(str(d))
#     while True:
#         for i in range(dc):
#             temp = int('9'*(dc-i)+'0'*i)
#             if temp != 0 and temp % d == 0:
#                 return temp, dc-i, i
#         dc += 1


# def getCircular(a, b):
#     i = a//b
#     a = a%b
#     d, nine, zero = findDenominator(b)
#     a *= d//b
#     return i, a, nine, zero



# a, b = 991, 994
# # a, b = 1, 7

# i, a, nine, zero = getCircular(a, b)
# a = str(a)
# print(i,'.',a[:zero],'(',a[zero:],')', sep='')


def div(a, b):
    already = [0]*b
    number = a//b
    decimals = []
    a %= b
    pos = 1
    already[a] = pos
    while True:
        pos += 1
        a *= 10
        decimals.append(a//b)
        a %= b
        if a == 0 or already[a] != 0:
            break
        already[a] = pos
    
    if a == 0:
        temp = '' if (len(decimals) == 1 and decimals[0] == 0) else ''.join(map(str,decimals))
        print(number,'.',temp,'(0)', sep='')
    else:
        print(number,'.',''.join(map(str,decimals[:already[a]-1])),'(',''.join(map(str,decimals[already[a]-1:])),')',sep='')

# div(1,7)
# div(995, 476)
# div(0,5)

n = int(sys.stdin.readline())
for _ in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    div(a,b)