def calculate(s: str) -> int:
    s = s.replace(' ', '')
    i = 0
    while (i < len(s)):
        if s[i] == ')':
            j = i-1
            while (s[j] != '('):
                j -= 1
            s = s[:j]+str(calculate(s[j+1:i]))+s[i+1:]
            i = j
        else:
            i += 1
    if len(s) == 0:
        return 0
    if s[0] != '+' and s[0] != '-':
        s = '+'+s

    ret = 0
    i = 0

    while (i < len(s)):
        count_minus = 0
        is_plus = True
        while (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                count_minus += 1
            i += 1
        is_plus = (count_minus % 2) == 0
        j = i
        while (j < len(s) and '0' <= s[j] <= '9'):
            j += 1
        ret += int(s[i:j]) if is_plus else -1*int(s[i:j])
        i = j

    return ret


# print(calculate("1 + 1"))
print(calculate("1+(     -2)"))
