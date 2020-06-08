/*************************************************************************
    > File Name: 6-20.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月08日 星期一 17时58分27秒
 ************************************************************************/

#include "Header.hpp"

class Solution {
public:

    //堆排的向下调整，beign代表在哪里开始调整
    void AdjustDown(vector<int>& nums,int begin)
    {
        //父亲下标索引
        int parent = begin;
        //孩子下标索引
        int child = parent * 2 + 1;

        while(child < nums.size())
        {
            //找到左右孩子中最大的一个下标
            if(child + 1 < nums.size() && nums[child] < nums[child + 1])
            {
                child = child + 1;
            }

            //判断孩子是否大于父亲
            //大于就交换
            if(nums[child] > nums[parent])
            {
                swap(nums[child],nums[parent]);
                parent = child;
                child = parent * 2 + 1;
            }
            //小于说明已经是一个堆了，可以直接return，因为我们在建堆的时候是
            //从下往上建的
            else 
            {
                break;
            }
        }
    }

    //三数取中，避免有序的情况
    int GetMidIndex(vector<int>& nums, int begin, int end)
    {
        int mid = begin + (end - begin) / 2;
        if(nums[begin] < nums[mid])
        {
            if(nums[mid] < nums[end])
            {
                return mid;
            }
            else if(nums[begin] > nums[end])
            {
                return begin;
            }
            else 
            {
                return end;
            }
        }
        else 
        {
            if(nums[mid] > nums[end])
            {
                return mid;
            }
            else if(nums[begin] < nums[end])
            {
                return begin;
            }
            else 
            {
                return end;
            }
        }
    }

    //快速排序hoare版本
    int PartSort1(vector<int>& nums, int begin, int end)
    {
        //找到合适的key
        int mid = GetMidIndex(nums,begin,end);
        swap(nums[mid],nums[begin]);
        int key = nums[begin];

        int start = begin;
        while(begin < end)
        {
            //从后往前找比key小的
            while(begin < end && nums[end] >= key)
            {
                end--;
            }

            //从前往后找比key大的
            while(begin < end && nums[begin] <= key)
            {
                begin++;
            }

            //交换
            swap(nums[begin],nums[end]);
        }
        //交换，将nums[start]放到正确的位置
        swap(nums[start],nums[begin]);
        return begin;
    }

    //快速排序挖坑版本
    int PartSort2(vector<int>& nums, int begin, int end)
    {
        //找到合适的key
        int mid = GetMidIndex(nums,begin,end);
        swap(nums[mid],nums[begin]);
        int key = nums[begin];

        while(begin < end)
        {
            //从后往前找比key小的
            while(begin < end && nums[end] >= key)
            {
                end--;
            }
            nums[begin] = nums[end];

            //从前往后找比key大的
            while(begin < end && nums[begin] <= key)
            {
                begin++;
            }
            nums[end] = nums[begin];
            
        }
        //将key放到正确的位置
        nums[begin] = key;
        return begin;
    }

    //快速排序双指针版本
    int PartSort3(vector<int>& nums, int begin, int end)
    {
        int key = nums[end];

        //后指针  
        int prev = begin - 1;
        //前指针
        int cur = begin;

        while(cur < end)
        {
            //cur如果找到比key小的元素，就将cur和prev的元素互换
            if(nums[cur] < key)
            {
                prev++;
                swap(nums[cur],nums[prev]);
            }
            //如果cur 所在下标的元素比key 所在元素大， 就直接后移cur
            cur++;
        }

        //最后注意和end 位置的元素交换的是pref 的下一个,不是它自己
        swap(nums[end],nums[++prev]);
        return prev;
    }

    //快排
    void QuickSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)
        {
            return ;
        }

        //if(right - left + 1 < 10)
        //{
            //  插入排序
        //}
        //else 
        {
            int mid = PartSort3(nums,left,right);
            QuickSort(nums,left,mid - 1);
            QuickSort(nums,mid + 1,right);
        }
    }

    //快排非递归
    void QuickSortStack(vector<int>& nums, int left, int right)
    {
        //用栈模拟递归
        stack<int> s;

        //往栈中放左右边界
        if(left < right)
        {
            s.push(right);
            s.push(left);
        }

        while(!s.empty())
        {
            //取左右边界时要注意边界的入栈顺序
            left = s.top();
            s.pop();
            right = s.top();
            s.pop();

            //进行单趟排序获取新的边界
            int mid = PartSort3(nums,left,right);

            //如果mid左边还有2个元素及以上继续入栈
            if(left < mid - 1)
            {
                s.push(mid - 1);
                s.push(left);
            }

            //右边同理
            if(right > mid + 1)
            {
                s.push(right);
                s.push(mid + 1);
            }
        }
    }

    //归并排序子程序
    void MergeChild(int*& nums,int left,int right,int* temp)
    {
        if(right <= left)
        {
            return ;
        }
        int mid = left + ((right - left) >> 1);

        MergeChild(nums,left,mid,temp);
        MergeChild(nums,mid + 1,right,temp);

        int begin1 = left;
        int end1 = mid;
        int begin2 = mid + 1;
        int end2 = right;

        int index = left;

        while(begin1 <= end1 && begin2 <= end2)
        {
            if(nums[begin1] <= nums[begin2])
            {
                temp[index++] = nums[begin1++];
            }
            else 
            {
                temp[index++] = nums[begin2++];
            }
        }

        while(begin1 <= end1)
        {
            temp[index++] = nums[begin1++];
        }

        while(begin2 <= end2)
        {
            temp[index++] = nums[begin2++];
        }

        memcpy(nums + left, temp + left, sizeof(int) * (right - left + 1));
    }

    //归并排序非递归子程序1
    void merge(int* nums, int left, int mid, int right, int* temp)
    {
        int begin1 = left, end1 = mid;
        int begin2 = mid + 1, end2 =right; 

        int index = left;

        while(begin1 <= end1 && begin2 <= end2)
        {
            if(nums[begin1] <= nums[begin2])
            {
                temp[index++] = nums[begin1++];
            }
            else 
            {
                temp[index++] = nums[begin2++];
            }
        }

        while(begin1 <= end1)
        {
            temp[index++] = nums[begin1++];
        }

        while(begin2 <= end2)
        {
            temp[index++] = nums[begin2++];
        }

        memcpy(nums + left, temp + left, sizeof(int) * (right - left + 1));
    }

    //归并排序非递归子程序2
    void mergePass(int* &arr, int k, int n, int *temp)
    {
        int i = 0;
        
        //从前往后,将 2 个长度为 k 的子序列合并为 1 个
        while(i < n - 2 * k + 1)
        {
            merge(arr, i, i + k - 1, i + 2 * k - 1, temp); 
            i += 2 * k;
        } 
        
        //合并区间[i, n - 1]有序的左半部分[i, i + k - 1]以及不及一个步长的
        //右半部分[i + k, n - 1] 
        if(i < n - k )
        {
            merge(arr, i, i + k - 1,n - 1, temp);
        }
    }

    // 归并排序非递归版
    void MergeSortNonR(int*& arr,int length)
    {
        int k = 1;
        int *temp = (int *)malloc(sizeof(int) * length); 
        while(k < length)
        {
            mergePass(arr, k, length,temp); 
            k *= 2;
        } 
        free(temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        /*插入排序：
        主要思想：假定一个位置end，end位置之前（包括end位置）的所有元素已经有序，end位置后
        的元素待判断；
        1:如果end之后位置的元素比end位置的元素大，不用往前插
        2:如果end之后位置的元素比end位置的元素小，需要往前插入到一个合适的位置（斗地主）
        */

        /*
        //排除特殊情况
        if(nums.empty())
        {
            return {};
        }

        //遍历，每次比较当前元素和下一个元素，所以只需要到size - 1即可
        for(size_t i = 0;i < nums.size() - 1;i++)
        {
            //end 为完成排序到最后一个元素下表，即end包括end之前到所有元素已经是有序的
            int end = i;

            //temp为end下一个位置的元素，即待判断的元素（判断temp元素和有序序列最后一个
            //位置的元素的大小）
            int temp = nums[end + 1];
            
            //1.temp刚好大于等于end位置的元素，我们求的是升序，满足情况，不进循环，执行:
            //nums[i + 1] = temp,相当于什么也没做，因为temp 也等于 nums[i+ 1]
            //2.temp刚好小于end位置的元素，代表后一个位置的元素小于前一个位置的元素，我们求的
            //是升序，不满足情况，进入循化；把当前end位置的元素往end + 1位置进行搬移
            //，继续判断是否满足情况，直到找到一个temp大于等于end位置元素的情况，即：
            //nums[?] < 或者 <= temp，直接把nums[end + 1]位置的元素值为temp即可，
            //（因为走到end这个位置，说明原来nums中end + 1位置的元素是大于等于temp的，
            //所以原来end + 1位置的元素肯定已经完成拷贝，所以可以直接复制）
            while(end >= 0 && nums[end] > temp)
            {
                nums[end + 1] = nums[end];
                end--;
            }
            nums[end + 1] = temp;
        }
        return nums;
        */

        /*希尔排序：
        主要思想：在插入排序的基础上加一个组gap，对每个gap进行插入排序。gap的值是动态递减的，
        直到gap = 1时就是插入排序
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        //不能直接些gap = nums.size() / 3 - 1
        int gap = nums.size();

        //不能写成大于 0,因为 gap的值始终>=1
        while(gap > 1)
        {
            //只有gap 最后为1， 才能保证最后有序
            //所以这里要加1
            gap = gap / 3 + 1;

            //这里只是把插入排序的1 换成gap 即可
            //但是这里不是排序完一个分组， 再去排序另一个分组， 而是整体只过一遍
            //这样每次对于每组数据只排一部分
            //整个循环结束之后， 所有组的数据排序完成

            //结束条件由size - 1变为size - gap，因为组的大小就是gap早size - gap时已经完成
            //size - 1位置元素的判断
            for (int i = 0; i < nums.size() - gap;++i)
            {
                //同样标记最后一个有序元素的下标
                int end = i;

                //同组带判断的下一个元素
                int temp = nums[end +gap];  

                while (end >= 0 && nums[end] >temp)
                {
                    nums[end + gap] = nums[end];
                    end -= gap;
                } 
                nums[end + gap] = temp; 
            }            
        }
        return nums;
        */

        /*
        选择排序（优化版）
        主要思想：一趟遍历选择一个最大的元素和一个最小的元素，并把最小的元素放在该趟排序
        的开始位置，把最大元素放在该趟排序的结束位置
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        //每趟循环查找的开始和结束位置
        int begin = 0;
        int end = nums.size() - 1;

        while(begin < end)
        {
            //每趟循化结束后，最大和最小元素的下标
            int max_data_index = begin;
            int min_data_index = begin;

            for(int i = begin;i <= end;i++)
            {
                //找最大元素下标
                if(nums[max_data_index] < nums[i])
                {
                    max_data_index = i;
                }

                //找最小元素下标
                if(nums[min_data_index] > nums[i])
                {
                    min_data_index = i;
                }
            }

            //把最小元素下标位置的元素放到该趟循化的开始位置
            swap(nums[begin],nums[min_data_index]);

            //有一种特殊情况，刚好最大元素的下标在该趟循化的开始位置
            //经过上面的交换之后，最大元素的下标被交换到min_data_index处，
            //需要注意
            if(max_data_index == begin)
            {
                max_data_index = min_data_index;
            }

            //把最大元素下标位置的元素放到该趟循化的结束位置
            swap(nums[end],nums[max_data_index]);

            begin++;
            end--;
        }
        return nums;
        */

        /*
        堆排：
        主要思想：升序建大堆，每次把大堆的堆顶元素和堆中最后一个位置的元素交换（可以保证堆顶
        元素一定是所有元素中最大的，但是不能保证最后一个元素是对中最小的，所以才用这种交换方式
        进行排序）
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        //根据nuns中的元素建大堆
        //在数组中：
        //根据孩子索引下标推父亲索引下标：parent = (child - 1) / 2;
        //根据父亲索引下标推孩子索引下标：child = parent * 2 + 1 / parent * 2 + 2

        //建堆是从下往上建造的，即先找到最后一个非叶子结点在数组中的下标，即：
        //根据子推父：parent = (nums.size() - 1 - 1) / 2;
        //逐渐往上建，直到nuns[0]
        for(int i = (nums.size() - 1 - 1) / 2;i >= 0;i--)
        {
            AdjustDown(nums,i);
        }

        //最后一个元素的位置
        int end = nums.size() - 1;

        //保存结果
        vector<int> ret(nums.size());

        //当nums中还有元素时
        while(end > 0)
        {
            //把第一个和最后一个元素进行交换
            swap(nums[0],nums[end]);

            //把最大的元素加入结果集
            ret[end] = nums[end];

            //不让最大的元素参加向下调整，因为其已经有序
            nums.pop_back();
            AdjustDown(nums,0);
            end-- ;
        }
        ret[0] = nums[0];
        return ret;
        */

        /*冒泡排序：
        主要思想：冒泡冒泡：顾名思义，一次冒出一个大的元素，其实和选择排序差不多
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        //避免有序的情况
        bool flag = true;

        //i代表每次循化的终点，i即i之后的元素是有序的，每次从前秒找到一个最大的放到i - 1处
        for(size_t i = nums.size();i > 0;i--)
        {
            //从0到i - 1中找最大
            for(size_t j = 1;j < i;j++)
            {
                if(nums[j - 1] > nums[j])
                {
                    flag = false;
                    swap(nums[j - 1],nums[j]);
                }
            }
            //如果没有进行一次交换说明nums本身就是有序的，直接beak掉
            if(flag)
            {
                break;
            }
        }
        return nums;
        */

        /*
        快速排序：
        主要思想：PartSort{1,2,3}及非递归
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        //QuickSort(nums,0,nums.size() - 1);
        QuickSortStack(nums,0,nums.size() - 1);

        return nums;
        */

        /*归并排序
        主要思想：归并排序子程序&归并排序非递归{1,2}
        */

        /*
        if(nums.empty())
        {
            return {};
        }

        int* temp = new int[(nums.size() * sizeof(int))];
        int* num = new int[(nums.size() * sizeof(int))];
        for(int i = 0;i < nums.size();i++)
        {
            num[i] = nums[i];
        }
        //MergeChild(num,0,nums.size() - 1,temp);
        MergeSortNonR(num,nums.size());
        for(int i = 0;i < nums.size();i++)
        {
            nums[i] = num[i];
        }
        return nums;
        */

        /*计数排序：
        主要思想：计数*/

        if(nums.empty())
        {
            return {};
        }

        map<int,int> mp;
        for(size_t i = 0;i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto e : mp)
        {
            for(int i = 0;i < e.second;i++)
            {
                nums.push_back(e.first);
            }
        }
        return nums;
    }
};

int main()
{

    return 0;
}

