import sys
# chupikachupipichu

s = sys.stdin.readline().strip()

i = 0
while i < len(s):
    if s[i] == 'p':
        if i+1 < len(s) and s[i+1] == 'i':
            i += 1
        else:
            print('NO')
            exit()
    elif s[i] == 'k':
        if i+1 < len(s) and s[i+1] == 'a':
            i += 1
        else:
            print('NO')
            exit()
    elif s[i] == 'c':
        if i+2 < len(s) and s[i+1] == 'h' and s[i+2] == 'u':
            i += 2
        else:
            print('NO')
            exit()   
    else:
        print('NO')
        exit()
    i += 1
print('YES')