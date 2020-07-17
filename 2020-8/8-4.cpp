/*************************************************************************
# File Name: 8-4.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月17日 星期五 11时55分08秒
*************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution 
{
    public:
        void Insert(int val)
        {
            if(Left_Max.empty() || val <= Left_Max.top())
            {
                Left_Max.push(val);
            }
            else 
            {
                Right_Min.push(val);
            }

            if(Left_Max.size() == Right_Min.size() + 2)
            {
                Right_Min.push(Left_Max.top());
                Left_Max.pop();
            }

            if(Left_Max.size() + 1 == Right_Min.size())
            {
                Left_Max.push(Right_Min.top());
                Right_Min.pop();
            }
        }

        double Median()
        {
            return Left_Max.size() == Right_Min.size() ? (Left_Max.top() + Right_Min.size()) / 2.0 : Left_Max.top();
        }

    private:
        priority_queue<int,vector<int>,less<int>> Left_Max;
        priority_queue<int,vector<int>,greater<int>> Right_Min;
};


int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    Solution so;

    for(auto e : arr)
    {
        so.Insert(e);
    }

    cout<<so.Median()<<endl;
    return 0;
}
