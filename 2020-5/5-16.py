
def dp(money, amount):
    # 如果金币的个数为0，直接返回-1
    if len(money) == 0:
        return -1

    # 如果选完一个金币后还需要选的金币的面额为0，就代表成功找到零钱
    # 本次就不需要选硬币，直接返回即可
    if amount == 0:
        return 0

    # 如果当前在上一次选完的基础上，发现本次需要选定硬币的面额为复数，说明上一次选的面额太大了
    # 直接返回-1，表示本次选择不成功，需要重新选择
    if amount < 0:
        return -1

    # 保存结果
    ret = float("inf")

    # 每次从列表当中选出一个硬币
    for coin in money:
        # temp代表选完本次硬币后剩下的硬币还需要选定个数
        temp = dp(money, amount - coin)

        # 如果temp == -1代表本次选择硬币的方案不合理，重新选择
        if temp == -1:
            continue

        # 记录需要最小的硬币个数,因为满足amount的硬币组合可能有多种
        ret = min(ret, temp + 1)

    if ret == float('inf'):
        return -1
    return ret

def coinChange(money, amount):
    return dp(money, amount)

if __name__ == "__main__":
    print(coinChange([2], 3))
