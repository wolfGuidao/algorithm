
# def findsubsets(nums, k):
#     list_ret = [[]]
#     if k == 0:
#         list_ret.append([])
#     else:
#         list_temp = findsubsets(nums, k - 1)
#         list_ret = list_temp
#         for i in range(0, len(list_temp)):
#             list_temp[i].append(nums[k - 1])
#             list_ret.append(list_temp[i])
#
#     return list_ret

# def subsets(nums):
#     return findsubsets(nums, len(nums))

def subsets(nums):
    ret = [[]]
    ret.append([])
    for i in range(0, len(nums)):
        size = len(ret)
        for j in range(0, size):
            temp = ret[i]
            temp.append(nums[i])
            ret.append(temp)

    return ret

if __name__ == "__main__":
    ret = subsets((1, 2, 3, 4))
    print(ret)
