#########################################################################
# File Name: 9-20.py
# Author: wolf
# mail: wolfguidao@163.com
# Created Time: 2020年09月26日 星期六 20时41分06秒
#########################################################################
#!/bin/python3
class Solution(object):
    def isPowerOfTwo(self, n):
        if n == 0:
            return False
        while n % 2 == 0:
            n /= 2
        return n == 1

