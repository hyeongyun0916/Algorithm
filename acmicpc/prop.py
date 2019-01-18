# 11920 버블정렬
# 시간초과..

# from collections import defaultdict

nk = [int(x) for x in input().split()]
nums = [int(x) for x in input().split()]
# nk = [4, 1]
# nums = [3,2,1,5,4]
# nums_dict = defaultdict(int)
# for i in nums:
#     nums_dict[i] += 1
# nums_copy = nums.copy()
# # nums[0] = 2
# # print(nums)
# # print(nums_copy)

# nums_copy.sort()
# # print(nums_copy)

for i in range(nk[1]):
    for j in range(0, len(nums)-1-i):
        if (nums[j] > nums[j+1]):
            temp = nums[j]
            nums[j] = nums[j+1]
            nums[j+1] = temp

for n in nums:
    print(n, end=' ')