/*************************************************************************
  > File Name: 7-27.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月09日 星期四 16时53分31秒
 ************************************************************************/

#include "Header.hpp"

#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
	//代表用例的个数
    int n;
    cin >> n;
 
    pair<int, int> xy;
 
    while (n--)
    {
    	//代表行数
    	int m;
        cin >> m;
 
 		//保存结果
        int count = 0;
        
        //存储上一行键值对出现的次数信息
        map<pair<int, int>, int> preFeaTimes;
        
        //存储本行键值对在上一行的基础上出现的次数信息
        map<pair<int, int>, int> feaTimes;
        
        while (m--)
        {
        	//代表每行键值对的个数
        	int len;
            cin >> len;
            for (int i = 0; i < len; i++)
            {
                cin >> xy.first >> xy.second;
                
                //判断如果本次输入的键值对在上一行出现过，那么该键值对的次数
                //等于上一行中记录的出现次数+1
                if (preFeaTimes.count(xy))
                    feaTimes[xy] = preFeaTimes[xy] + 1;
                else
                //如果该键值对没有出现过或者没在上一行出现过，说明该键值对
                //要么根本没出现过要么中间断了，所以重新置为1
                    feaTimes[xy] = 1;
 
                count = max(count,feaTimes[xy]);
               
            }
            //注意注意⚠️⚠️，这里的清空和交换非常重要
            //正式因为有这两个操作才完成每次记录的都是本行和上一行键值对出现的信息
            //清理：是因为本行已经遍历完了，键值对的更新信息已经保存在feaTimes中了
            preFeaTimes.clear();
            //swap：是因为要继续判断下一行的键值对信息，下一行是依赖本行的
            preFeaTimes.swap(feaTimes);
            //总结：就是通过这两个操作完成判读最长连续出现的键值对
        }
        cout << count << endl;
    }
 
    return 0;
}
