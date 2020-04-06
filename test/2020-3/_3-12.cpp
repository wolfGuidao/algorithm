class Solution {
  public:
    string PrintMinNumber(vector<int> numbers) {
      if(numbers.empty())
      {
        return "";

      }

      //主要思想是把第一位数大的拼接到最后
      //自定义比较方式
      //首先按照两个数的第一位的进行比较，如果第一位相等在往后比较第二位，如果位数
      //不相等还是一第一位为准，第一位大就是大
      //这种比较方式就是字符串的比较方式
      sort(numbers.begin(),numbers.end(),[](int a,int b)
          {
          string stra = to_string(a) + to_string(b);
          string strb = to_string(b) + to_string(a);
          return stra < strb;
          });

      //拼接
      string ret;
      for(auto e : numbers)
      {
        ret += to_string(e);
      }
      return ret;
    }
};
}
})
}
}
