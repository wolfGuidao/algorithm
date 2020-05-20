
# def rob(nums):
#     def dp(start):
#         if start >= len(nums):
#             return 0
#
#         ret = max(dp(start + 1), dp(start + 2) + nums[start])
#
#         return ret
#     return dp(0)

# def rob(nums):
#     dp_i_1 = 0
#     dp_i_2 = 0
#     dp_i_0 = 0
#     for money in range(len(nums) - 1, -1, -1):
#         dp_i_0 = max(dp_i_1, dp_i_2 + nums[money])
#         dp_i_2 = dp_i_1
#         dp_i_1 = dp_i_0
#
#     return dp_i_0

def rob(nums, start, end):
    dp_i_1 = 0
    dp_i_2 = 0
    dp_i_0 = 0
    for money in range(end, start - 1, -1):
        dp_i_0 = max(dp_i_1, dp_i_2 + nums[money])
        dp_i_2 = dp_i_1
        dp_i_1 = dp_i_0

    return dp_i_0

if __name__ == "__main__":
    list_nums = [2,3,2]
    print(max(rob(list_nums, 0, len(list_nums) - 2), rob(list_nums, 1, len(list_nums) - 1)))

