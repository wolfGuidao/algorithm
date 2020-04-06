
class Solution {
  public:
    //求横坐标或者纵坐标的数位之和
    int GetSum (int i)
    {
      int count = 0;
      while(i)
      {
        count += i%10;
        i /= 10;
      }
      return count;
    }

    //递�始移动
    //threshold代表用户输入的K，
    //i和j代表当前的位置
    //flag用来标记哪些位置已经走过
    int move(int& threshold,int rows,int cols,int i,int j,vector<bool>& flag)
    {
      int count = 0;
      //如果i和j在给定的行列范围内进行移动，并且行列坐标的数位之和没有超过给定值，并且
      //i和j这个位置没有被走过；满足这些条件才可以进行移动
      if(i >= 0 && i < rows && j >= 0 && j < cols && GetSum(i) + GetSum(j) <= threshold && flag[i * cols + j] == false)
      {
        //把该位置置为true，代表该位置已经被遍历过，下一次不用对此位置计数
        flag[i * cols + j] = true;
        count = 1 + move(threshold,rows,cols,i,j - 1,flag)//上
          + move(threshold,rows,cols,i,j + 1,flag)//下
          + move(threshold,rows,cols,i - 1,j,flag)//左
          + move(threshold,rows,cols,i + 1,j,flag);//右
        //count的结果是上下左右所有可以到达的坐标之和
      }

      return count;
    }

    int movingCount(int threshold, int rows, int cols)
    {
      if(rows < 0||cols < 0 || threshold < 0)
      {
        return 0;
      }

      vector<bool> flag(rows * cols,false);


      int count = move(threshold,rows,cols,0,0,flag);
      return count;
    }
};



}
}
}
}
}
}
}
