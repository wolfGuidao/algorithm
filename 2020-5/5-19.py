
def min_distance(s1, s2):
    def dp(i, j):
        if i == -1:
            return j + 1
        if j == -1:
            return i + 1
        if s1[i] == s2[j]:
            return dp(i - 1, j - 1)
        else:
            return min(
                dp(i - 1, j) + 1,
                dp(i, j - 1) + 1,
                dp(i - 1, j - 1) + 1
            )

    return dp(len(s1) - 1, len(s2) - 1)

def main():
    str1 = "horse"
    str2 = "ros"
    print(min_distance(str1, str2))

if __name__ == "__main__":
    main()
