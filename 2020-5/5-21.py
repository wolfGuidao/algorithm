
def longestCommonSubsequence(str1, str2):
    def dp(i, j):
        if i == -1 or j == -1:
            return 0
        if str1[i] == str2[j]:
            return dp(i - 1, j - 1) + 1
        else:
            return max(dp(i, j - 1), dp(i - 1, j))
    return dp(len(str1) - 1, len(str2) - 1)

def main():
    str1 = "abcde"
    str2 = "ace"
    print(longestCommonSubsequence(str1, str2))

if __name__ == "__main__":
    main()
