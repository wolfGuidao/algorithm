# chessboard = []
# black = []
# wilte = []
# count = 0
#
# def Check(list_chess, line):
#     i = 1
#     for i in range(1, line):
#         temp = list_chess[line] - list_chess[i]
#         if temp == 0 or temp == i - line or temp == line - i:
#             return False
#     return True
#
# def Wilte(n, line):
#     global count
#     if line == n + 1:
#         count += 1
#         return
#     for i in range(1, n + 1):
#         if chessboard[line][i] == 1 and black[line] != i:
#             wilte[line] = i
#             if Check(wilte, line):
#                 Wilte(n, line + 1)
#
# def Black(n, line):
#     if line == n + 1:  # 如果当前行数等于总行数 + 1，就代表找到黑皇后的放置位置，接下来第归判断白皇后即可
#         return Wilte(n, 1)
#     for i in range(1, n + 1):  #
#         if chessboard[line][i] == 1:
#             black[line] = i
#             if Check(black, line):
#                 Black(n, line + 1)
#
#
# if __name__ == "__main__":
#     n = int(input("input n: "))
#     chessboard = [[0 for i in range(n + 2)]for j in range(n + 2)]
#     for _ in range(n):
#         chessboard.append(list(map(int, input("input list: ").rstrip().split())))
#     for i in range(n):
#         print(chessboard[i])
#     # chessboard = [[0 for i in range(n + 2)]for j in range(n + 2)]
#     # for i in range(1, n + 1):
#     #     for j in range(1, n + 1):
#     #         chessboard[i][j] = input("list:")
#     black = [0 for i in range(n)]
#     wilte = [0 for i in range(n)]
#     Black(n, 1)
#     print("一共有{}种放置方法".format(count))

import math

cnt = 0

# 判断是否可以放置皇后
def issafe(d, row):
    for i in range(row):
        # 在同一列、同一个对角线都不可以放置皇后
        if d[i] == d[row] or math.fabs(i - row) == math.fabs(d[i] - d[row]):
            return False
    return True

# 放置另一种颜色的皇后
def blackDfs(c, d, n, row):
    global cnt
    # 如果当前行数等于棋盘总行数，就代表剩下一种颜色
    # 的皇后也已经放置完毕，把结果+ 1
    if row == n:
        cnt += 1
        return

    # d的作用和和b的作用一样，记录已经放置皇后的位置
    d[row] = 0

    while d[row] < n:
        if c[row][d[row]] == 1 and issafe(d, row):
            blackDfs(c, d, n, row + 1)
        d[row] += 1


# 放置第一种颜色的皇后
def dfs(a, b, n, row):
    # 如果当前行数和棋盘总行数相等，就说明已经成功放置一种颜色的说有皇后
    if row == n:
        # 把棋盘中的数据拷贝一份放到c当中
        c = [[0 for i in range(n)]for i in range(n)]
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j]  # save a to c

        # 把棋盘中已经成功放置皇后的位置置为0，代表不可以再次放置皇后
        for i in range(n):
            c[i][b[i]] = 0

        # 第归放置另一种颜色的皇后
        d = [0 for i in range(n)]
        blackDfs(c, d, n, 0)
        return

    # b是用来记录每一行皇后放置的位置
    b[row] = 0
    while b[row] < n:
        # 如果棋盘中对应的位置为1，代表可以放置皇后，并且满足放置皇后的条件
        if a[row][b[row]] == 1 and issafe(b, row):
            # 继续第归放置下一行
            dfs(a, b, n, row + 1)
        b[row] += 1


def main():
    n = int(input("请输入棋盘大小:"))

    a = []
    # a = [[0 for i in range(n)]for i in range(n)]
    b = [0 for i in range(n)]

    for i in range(n):
        a .append(list(map(int, input("list: ").rstrip().split())))
    print(a)

    # a代表棋盘， b代表临时保存皇后位置的列表， n代表棋盘的大小，
    # 0代表从棋盘的第几行开始放置数据
    dfs(a, b, n, 0)
    print("共有{}种放置皇后的方法！".format(cnt))


if __name__ == '__main__':
    main()
