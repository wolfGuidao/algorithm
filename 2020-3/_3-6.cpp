class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
      //保存结果
      vector<vector<int>> ret;
      if(A.empty() || B.empty())
      {
        return ret;
      }

      //i和j两个下标索引
      int i = 0;
      int j = 0;
      while(i < A.size() && j < B.size())
      {
        //下面四个变量的含义相见博客
        int a1 = A[i][0];
        int a2 = A[i][1];
        int b1 = B[j][0];
        int b2 = B[j][1];

        //代表区间有交集，自己画个图就OK
        if(b2 >= a1 && a2 >= b1)
        {
          //max(a1,b1),min(a2,b2)两个区间的交集部分
          ret.push_back({max(a1,b1),min(a2,b2)});
        }

        //更新i和j下标索引，b2 < a2 就代表i所在的区间大于j所在的区间，更新j
        //是因为i区间长于j区间的部分还可能和j的下一个区间继续重叠，还需要继续判断
        //所以更新j而不是更新i
        if(b2 < a2)
        {
          j++;
        }
        else//反之同理
        {
          i++;
        }
      }   
      return ret;
    }
};

}
}
}
}
}
}
}
