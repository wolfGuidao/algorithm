class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      int* top = new int[nums.size()];

      // 牌堆数初始化为 0
      int piles = 0;

      //遍历nums中的每一个元素
      for (int i = 0; i < nums.size(); i++) 
      {
        // 要处理的扑克牌，保存一下
        int poker = nums[i];

        /***** 搜索左侧边界的⼆分查找 *****/
        int left = 0;
        int right = piles;
        while (left < right) 
        {
          int mid = (left + right) / 2;
          if (top[mid] > poker)
          {
            right = mid;
          } 
          else if (top[mid] < poker) 
          {
            left = mid + 1;
          } 
          else 
          {
            right = mid;
          }
        } 
        /*********************************/
        // 没找到合适的牌堆， 新建⼀堆
        if (left == piles) 
          piles++;

        // 把这张牌放到牌堆顶
        top[left] = poker;
      } 
      // 牌堆数就是 最长递增序列 ⻓度
      return piles;

    }
};
