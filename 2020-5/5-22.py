
# k == 1
def maxProfit_k_1(prices):
    dp_i_0 = 0
    dp_i_1 = float("-inf")

    for i in prices:
        dp_i_0 = max(dp_i_0, dp_i_1 + i)
        dp_i_1 = max(dp_i_1, -i)

    return dp_i_0

# k == float("inf")
def maxProfit_k_inf(prices):
    dp_i_0 = 0
    dp_i_1 = float("-inf")

    for price in prices:
        temp = dp_i_0
        dp_i_0 = max(dp_i_0, dp_i_1 + price)
        dp_i_1 = max(dp_i_1, temp - price)
    return dp_i_0

# k == inf and cool == 1
def maxProfit_k_inf_with_cool(prices):
    dp_i_0 = 0
    dp_i_1 = float("-inf")
    dp_pre_0 = 0

    for price in prices:
        temp = dp_i_0
        dp_i_0 = max(dp_i_0, dp_i_1 + price)
        dp_i_1 = max(dp_i_1, dp_pre_0 - price)
        dp_pre_0 = temp
    return dp_i_0


# k == inf and free money
def maxProfit_k_inf_free_money(prices, free_money):
    dp_i_0 = 0
    dp_i_1 = float("-inf")

    for price in prices:
        temp = dp_i_0
        dp_i_0 = max(dp_i_0, dp_i_1 + price)
        dp_i_1 = max(dp_i_1, temp - price - free_money)

    return dp_i_0


# k == 2
# def maxProfit_k_2(prices):
#     dp_i_k_0 = 0
#     dp_i_k_1 = float("-inf")
#
#     for price in prices:
#         for k in range(2, 0, -1):
#             temp = dp_i_k_0
#             dp_i_k_0 = max(dp_i_k_0, dp_i_k_1 + price)
#             dp_i_k_1 = max(dp_i_k_1, temp - price)
#
#     return dp_i_k_0
def maxProfit_k_2(prices):
    pass

if __name__ == "__main__":
    list_prices = [3,3,5,0,0,3,1,4]
    print(maxProfit_k_2(list_prices))
