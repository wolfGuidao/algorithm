/*************************************************************************
    > File Name: 6-26.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月13日 星期六 15时00分53秒
 ************************************************************************/

#include "Header.hpp"

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        // 10     9   8   7   6   5  4 3 2 1 0
        // 1024  512 256 128 64  32 16 8 4 2 1
        //|0 1    0   0 |  0  0  0  0 |0 0 0 0 :1024:n
        //|0 0    0   0    0  0  0  1  0 0 1 1  :19:m
        //|0 1    0   0    0  1  0  0  1 1 0 0 :1100
        int temp1 = 1;
        int temp2;
        for(int x = j;x <= i;x++)
        {
            temp2 = (m & temp1);
            cout<<temp2<<endl;
            if(temp2)
            {
                cout<<__LINE__<<endl;
                n |= (temp2 << j);
            }
            temp1 = (temp1 << 1);
        }
        return n;
    }
};

int main()
{
    cout<<BinInsert().binInsert(1024,19,2,6)<<endl;
    return 0;
}

