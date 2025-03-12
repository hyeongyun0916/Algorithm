import sys


def is_repeated_substring(s):
    len_s = len(s)
    return s[:len_s // 2] == s[len_s // 2:]


def count_repeated_substring(S):
    count = 0
    len_s = len(S)
    for i in range(1, len_s, 2):
        len_substr = i+1
        j = 0
        while j + len_substr <= len_s:
            sub_str = S[j:j + len_substr]
            if sub_str[:len_substr // 2] == sub_str[len_substr // 2:]:
                count += 1
            j += len_substr // 2
        j = 1
        while j + len_substr <= len_s:
            sub_str = S[j:j + len_substr]
            if sub_str[:len_substr // 2] == sub_str[len_substr // 2:]:
                count += 1
            j += len_substr // 2
    return count


# print(count_repeated_substring("ab"*4))
print(count_repeated_substring("ab"*5))
# print(count_repeated_substring("ab"*6))

# print(count_repeated_substring("abc"*3))
# print(count_repeated_substring("abc"*4))
# print(count_repeated_substring("abc"*5))
