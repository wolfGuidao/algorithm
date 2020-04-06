class Solution {
  public:
    int dp(string word1,string word2,int i,int j)
    {
      //规定 i 用来遍历word1， j 用来遍历word2，如果有 i 或者 j 小于0，代表其遍历当字符串已经走完，直接返回对方字符串剩下的字���串长度（要么是删除，要么是插入，加上所需的次数即可）
      if(i < 0)
      {
        return j + 1;
      }

      if(j < 0)
      {
        return i + 1;
      }

      //如果i和j对应位置的字符相等，不用任何操作，直接返回继续比较下一个字符
      if(word1[i] == word2[j])
      {
        return dp(word1,word2,i-1,j-1);
      }
      else
      {
        //如果i和j对应位置的字符不想等，就返回删除、替换、插入三种所需要的操作数的最小值，详细博客中国年有介绍
        int Min = min(dp(word1,word2,i,j-1) + 1,
            dp(word1,word2,i-1,j) + 1);
        Min = min(Min,dp(word1,word2,i-1,j-1) + 1);
        return Min;
      }
    }
    int minDistance(string word1, string word2) {
      //当word1和word2有任意一个为空时，直接返回对方当长度，因为要么是删除，要么是插入，操作的次数都是对方当长度
      if(word1.empty())
      {
        return word2.size();
      }

      if(word2.empty())
      {
        return word1.size();
      }

      return dp(word1,word2,word1.size() - 1,word2.size() - 1);
    }
};
}
}
}
}
}
}
}
}
}
