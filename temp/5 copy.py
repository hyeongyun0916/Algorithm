# 6/18
def get_value(A):
    value = 0
    for i in range(len(A)-1):
        value += A[i] * A[i+1]
    value += A[-1] * A[-0]
    return value


def minimize_multiplication(A):
    len_A = len(A)
    value = get_value(A)
    for i in range(len_A-1):
        j = 2
        while i+j <= len_A:
            B = A.copy()
            B[i:i+j] = A[i:i+j][::-1]
            value = min(value, get_value(B))
            j += 1
    return value


print(minimize_multiplication([1, 2, 3, 4]))
print(minimize_multiplication([1, 1]))