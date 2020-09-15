import sys

# def compress(s, n):
#     newStr = ''
#     i = 0
#     while i <= len(s)-n:
#         unit = s[i:i+n]
#         num = 1
#         while unit == s[i+n:i+n+n]:
#             i += n
#             num += 1
#         if num > 1:
#             i += n
#             newStr += str(num) + unit
#         else:
#             newStr += s[i]
#             i += 1
#     newStr += s[i:]
#     return len(newStr)

def compress(s, n):
    strs = []
    i = 0
    while i < len(s)//n:
        strs.append(s[i*n:i*n+n])
        i += 1
    if len(s)%n != 0:
        strs.append(s[i*n:])
    newStr = ''
    i = 0
    oriI = i
    while i < len(strs):
        oriI = i
        while i+1 < len(strs) and strs[i] == strs[i+1]:
            i += 1
        if oriI != i:
            newStr += str(i-oriI+1)+strs[i]
        else:
            newStr += strs[i]
        i += 1
    return len(newStr)

def solution(s):
    answer = len(s)
    for i in range(int(len(s)/2)+1):
        answer = min(answer, compress(s, i+1))
    return answer