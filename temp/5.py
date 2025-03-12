def get_value(A):
    value = 0
    for i in range(len(A)-1):
        value += A[i] * A[i+1]
    value += A[-1] * A[-0]
    return value


def minimize_multiplication(A):
    n = len(A)
    
    total = 0
    for i in range(n-1):
        total += A[i] * A[i+1]
    total += A[-1] * A[-0]

    answer = total
    for i in range(n-1):
        j = 2
        while i+j < n:
            answer = min(answer,
                         total - A[i]*A[i-1] - A[i+j-1]*A[i+j] +
                         A[i]*A[i+j] + A[i+j-1]*A[i-1])
            j += 1
    return answer


print(minimize_multiplication([1, 2, 3, 4]))
# print(minimize_multiplication([1, 1]))
