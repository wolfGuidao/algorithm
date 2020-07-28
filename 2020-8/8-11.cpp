/*************************************************************************
# File Name: 8-11.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月27日 星期一 19时50分39秒
 *************************************************************************/

namespace wolf
{
    template <class T, class Sequence = vector<T>, class Compare = less<T> >
        class priority_queue
        {
            public:
                priority_queue() : c()
            {}
                template <class InputIterator>
                    priority_queue(InputIterator first, InputIterator last)
                    : c(first, last)
                    {
                        make_heap(c.begin(), c.end(), comp);
                    }
                bool empty() const { return c.empty(); }
                size_t size() const { return c.size(); }
                T& top() const { return c.front(); }
                void push(const T& x)
                {
                    c.push_back(x);
                    push_heap(c.begin(), c.end(), comp);
                }
                void pop()
                {
                    pop_heap(c.begin(), c.end(), comp);
                    c.pop_back();
                }
            private:
                Sequence c;
                Compare comp;
        };
}

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Usage() 
{
    printf("usage: ./server [ip] [port]\n");
}
int main(int argc, char* argv[]) 
{
    if (argc != 3) {
        Usage();
        return 1;
    }
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("socket");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0)
    {
        perror("bind");
        return 1;
    }
    ret = listen(fd, 10);
    if (ret < 0)
    {
        perror("listen");
        return 1;
    }
    for (;;) 
    {
        struct sockaddr_in client_addr;
        socklen_t len;
        int client_fd = accept(fd, (struct sockaddr*)&client_addr, &len);
        if (client_fd < 0)
        {
            perror("accept");
            continue;
        }
        char input_buf[1024 * 10] = {0}; // 用一个足够大的缓冲区直接把数据读完.
        ssize_t read_size = read(client_fd, input_buf, sizeof(input_buf) - 1);
        if (read_size < 0)
        {
            return 1;
        }
        printf("[Request] %s", input_buf);
        char buf[1024] = {0};
        const char* hello = "<h1>hello world</h1>";
        sprintf(buf, "HTTP/1.0 200 OK\nContent-Length:%lu\n\n%s", strlen(hello), hello);
        write(client_fd, buf, strlen(buf));
    }
    return 0;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        if(nums.size() == 1)
        {
            return nums[0];
        }

        /*
        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());
        
        dp_min[0] = nums[0];
        dp_max[0] = nums[0];

        for(int i = 1;i < nums.size();i++)
        {
            dp_max[i] = max(
                dp_max[i - 1] * nums[i],max(
                    nums[i],dp_min[i - 1] * nums[i]
                )
            );

            dp_min[i] = min(
                dp_min[i - 1] * nums[i],min(
                    nums[i],dp_max[i - 1] * nums[i]
                )
            );
        }

        int ret = INT_MIN;
        for(auto e : dp_max)
        {
            ret = max(ret,e);
        }
        return ret;
        */

        int dp_max = nums[0];
        int dp_min = nums[0];
        int ret = dp_max;

        for(int i = 1;i < nums.size();i++)
        {
            int max_temp = dp_max;
            int min_temp = dp_min;
            dp_max = max(max_temp * nums[i],max(nums[i],min_temp * nums[i]));
            dp_min = min(min_temp * nums[i],min(nums[i],max_temp * nums[i]));
            ret = max(ret,dp_max);
        }

        return ret;
    }
};

/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
        {
            return 0;
        }

        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i = 0;i < matrix.size();i++)
        {
            for(int j = 0;j < matrix[i].size();j++)
            {
                if(j == 0)
                {
                    if(matrix[i][j] == '0')
                    {
                        dp[i][j] = 0;
                    }
                    else 
                    {
                        dp[i][j] = 1;
                    }
                }
                else if(matrix[i][j] == '1')
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                else if(matrix[i][j] == '0')
                {
                    dp[i][j] = 0;
                }
            }
        }

        int Max_area = INT_MIN;
        for(int i = 0;i < matrix.size();i++)
        {
            for(int j = 0;j < matrix[i].size();j++)
            {
                int col = INT_MAX;
                int row = 0;
                for(int k = i;k >= 0;k--)
                {
                    col = min(col,dp[k][j]);
                    row++;
                    
                    Max_area = max(Max_area,min(col,row) * min(col,row));
                    if(dp[k][j] == 0)
                    {
                        col = INT_MAX;
                        row = 0;
                    }
                }
            }
        }
        return Max_area;
    }
};
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int maxSide = 0;

        int rows = matrix.size(), columns = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(columns));

        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < columns; j++) 
            {
                if (matrix[i][j] == '1') 
                {
                    if (i == 0 || j == 0) 
                    {
                        dp[i][j] = 1;
                    } 
                    else 
                    {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};

