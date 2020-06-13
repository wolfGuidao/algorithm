
def maxA(N):
    dp = (i for i in range(0, N + 1))
    dp[0] = 0

    for i in range(1, N + 1):
        dp[i] = dp[i - 1] + 1

        for j in range(2, i):
            dp[i] = max(dp[i], dp[j - 2] * (i - j + 1))

    return dp[N]

if __name__ == "__main__":
    print(maxA(3))
