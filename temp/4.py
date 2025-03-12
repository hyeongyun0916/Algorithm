def divide(A):
    max_value = 0
    for i in range(len(A)):
        max_value = max(max_value, A[i])
    
    divided_A = []
    pos = 0
    for i in range(len(A)):
        if A[i] == max_value:
            if pos < i:
                divided_A.append(A[pos:i])
            pos = i+1
    if pos < len(A):
        divided_A.append(A[pos:])
    return divided_A, max_value


def get_value(A, goal):
    if len(A) == 1:
        return goal - A[0]
    same = True
    for i in range(len(A)):
        if A[i] != A[0]:
            same = False
            break
    if same:
        return goal - A[0]

    divided_A, max_value = divide(A)
    answer = 0
    for i in range(len(divided_A)):
        answer += get_value(divided_A[i], max_value)

    return answer + goal - max_value


def get_operation_number(A):
    divided_A, max_value = divide(A)
    answer = 0
    for i in range(len(divided_A)):
        answer += get_value(divided_A[i], max_value)

    return answer


# print(get_operation_number([1, 1, 4, 2]))
print(get_operation_number([3, 1, 3, 2, 2, 4, 3, 1, 3, 2, 2, 5]))
