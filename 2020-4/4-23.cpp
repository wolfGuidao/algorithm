#include "Header.hpp"

class GrayCode {
  public:
    vector<string> getGray(int n) {
      // write code here
      if(n == 1)
      {
        return {"0","1"};
      }
      vector<string> s1 = getGray(n - 1);//递归调用
      vector<string> s2(2 * s1.size());

      for(int i = 0;i < s1.size();i++)
      {
        s2[i] = "0" + s1[i];//首位添加0

        //首位添加1，注意需要顺序反向
        s2[i + s1.size()] = "1" + s1[s1.size() - 1 - i];
      }
      return s2;
    }
};


}
}
}
}
