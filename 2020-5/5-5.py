
# def Func(n):
#     if n == 1 or n == 2:
#         return n
#
#     return Func(n - 1) + Func(n - 2)
#
# def main():
#     try:
#         n = int(input("input n:"))
#     except:
#         print("you input num is bad")
#     else:
#         print(Func(n))

# def Func(n):
#     if n == 0 or n == 1 or n == 2:
#         return n
#
#     return 2 * Func(n - 1)
#
# def main():
#     try:
#         n = int(input("input n:"))
#     except:
#         print("you input num is bad")
#     else:
#          print(Func(n))

# flag_count = 0;
#
# def Move(n, a, c):
#     global flag_count
#     flag_count += 1
#     print("this is %d moved,used %d from %s to %s" % (flag_count, n, a, c));
#
# def Func(n, a, b, c):
#     if n == 1:
#         Move(n, a, c)
#     else:
#         Func(n - 1, a, c, b)
#         Move(n, a, c)
#         Func(n - 1, b, a, c)
#
# def main():
#     str1 = 'a'
#     str2 = 'b'
#     str3 = 'c'
#     Func(3, str1, str2, str3)


def Func(year):
    if year == 0 or year == 1 or year == 2 or year == 3:
        return year
    return Func(year - 3) + Func(year - 1)

def main():
    print("now years have cows is {}".format(Func(4)))

if __name__ == "__main__":
    main()
