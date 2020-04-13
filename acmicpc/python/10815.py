arr = []
arr_len = int(input())
arr = [int(x) for x in input().split()]
#for i in range(0, arr_len):
#    temp = int(input())
#    arr.append(temp)
arr.sort()

def bin_find(arr, a):
    my_min = 0
    my_max = len(arr)-1
    while my_max >= my_min:
        i = int((my_min+my_max)/2)
        if arr[i] == a:
            return 1
        elif arr[i] < a:
            my_min = i+1
        else:
            my_max = i-1
    return 0


to_find_len = int(input())
to_find = [int(x) for x in input().split()]
for i in range(0, to_find_len):
    print(bin_find(arr, to_find[i]), end=' ')