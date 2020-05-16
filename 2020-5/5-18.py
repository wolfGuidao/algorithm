
def lengthOfLIS(nums):
    if len(nums) == 0:
        return 0
    dp = [1] * len(nums)

    for i in range(0, len(nums)):
        for j in range(0, i):
            if int(nums[j]) < int(nums[i]):
                dp[i] = max(dp[i], dp[j] + 1)

    ret = 0
    for i in range(0, len(dp)):
        ret = max(ret, dp[i])

    return ret

if __name__ == "__main__":
    list_ = [10,9,2,5,3,7,101,18]
    print(lengthOfLIS(list_));
