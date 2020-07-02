/*************************************************************************
    > File Name: 7-15.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月02日 星期四 15时55分25秒
 ************************************************************************/

#include "Header.hpp"

#if 0
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    // 1 2 1 1 1
    
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        //int len = arr.size();
        /*
        int left = 0;
        int right;
        if((len - 1) % 2 == 0)
        {
            right = len - 2;
        }
        else 
        {
            right = len - 1;
        }
        
        //     0             3
        while(left < len && right >= 0)
        {
            while(left < len && right >= 0 && arr[right] % 2 != 0)
            {
                right -= 2;
            }
            
            while(left < len && right >= 0 && arr[left] % 2 == 0)
            {
                left += 2;
            }
            if(left < len && right >= 0)
                swap(arr[left],arr[right]);
        }
        */
        
        int num_0 = 0;
        int num_1 = 1;
        
        while(num_0 < len && num_1 < len)
        {
            while(num_0 < len && arr[num_0] % 2 == 0)
            {
                num_0 += 2;
            }
            
            while(num_1 < len && arr[num_1] % 2 != 0)
            {
                num_1 += 2;
            }
            
            if(num_1 < len && num_0 < len)
                swap(arr[num_0],arr[num_1]);
        }
    }
};
#endif 
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    // 1 2 1 1 1
    
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        if(len <= 2)
        {
            return ;
        }
        //int len = arr.size();
        /*
        int left = 0;
        int right;
        if((len - 1) % 2 == 0)
        {
            right = len - 2;
        }
        else 
        {
            right = len - 1;
        }
        
        //     0             3
        while(left < len && right >= 0)
        {
            while(left < len && right >= 0 && arr[right] % 2 != 0)
            {
                right -= 2;
            }
            
            while(left < len && right >= 0 && arr[left] % 2 == 0)
            {
                left += 2;
            }
            if(left < len && right >= 0)
                swap(arr[left],arr[right]);
        }
        */
        
        /*
        int num_0 = 0;
        int num_1 = 1;
        
        while(num_0 < len && num_1 < len)
        {
            while(num_0 < len && arr[num_0] & 1 == 0)
            {
                num_0 += 2;
            }
            
            while(num_1 < len && arr[num_1] & 1 == 1)
            {
                num_1 += 2;
            }
            
            if(num_1 < len && num_0 < len)
            {
                //swap(arr[num_0],arr[num_1]);
                
                int temp = arr[num_0];
                arr[num_0] = arr[num_1];
                arr[num_1] = temp;
                
            }
        }
       */
        int odd = 1;
        int even = 0;
        while (odd < len && even < len)
        {
            if (arr[odd] % 2 == 0)
            {
                while (arr[even] % 2 == 0)
                {
                    even += 2;
                }
                if (even < len)
                {
                    //swap(arr[even],arr[odd]);
                    
                    int tmp = arr[even];
                    arr[even] = arr[odd];
                    arr[odd] = tmp;
                    
                }
                else
                {
                    break;
                }
            }
            else
            {
                odd += 2;
            }
        }
    }
};

int main()
{
    vector<int> arr = {1,2,3,4};
    Solution().oddInOddEvenInEven(arr,4);
    for(auto e : arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}

