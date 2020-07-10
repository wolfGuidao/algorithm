#########################################################################
# File Name: 7-01.py
# Author: wolf
# mail: wolfguidao@163.com
# Created Time: 2020年07月09日 星期四 19时30分50秒
#########################################################################
#!/bin/python3
import re

def func():
    # str = "i am wolf, i age is 22, i am boy"
    # str = "<html>hellowolf22forever</html>"
    # result = re.search(r'<html>([a-zA-Z]+)(\d+)\1</html>', str);
    # print(result)
    # print(result.group(1))
    # print(result.group(2))
    # print(result.group(3))
    # print(result.group())
    print(re.search(r'(?P<name>go)\s+(?P=name)\s+(?P=name)', 'go go go').group('name'))
    print(re.search(r'(go)\s+\1\s+\1', 'go go go').group())
    result = re.match(r'(go)\s+\1\s+\1', 'go go go')
    print(result.group(1))

def main():
    func()

if __name__ == "__main__":
    main()

