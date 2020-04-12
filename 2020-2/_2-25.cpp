#include "Header.hpp"

void Select(vector<int>& arr)
{

  int begin = 0;//记录每次开始比较的位置，因为随着排序的进行，区间不断的缩小
  int end = static_cast<int>(arr.size() - 1);//记录每次排序区间的 结束位置

  while(begin <= end)//排序区间
  {
    int Min = begin;//记录每趟最小元素的下标
    int Max = end;//记录每趟最大元素的下标
    for(int i = begin;i <= end;i++)//在区间中找最小和最大元素的下标
    {
      //更新下标
      if(arr[Min] > arr[i])
      {
        Min = i;
      }
      if(arr[Max] < arr[i])
      {
        Max = i;
      }
    }
    //交换
    swap(arr[begin],arr[Min]);
    if(Max == begin)
    {
      Max = Min;
    }
    swap(arr[end],arr[Max]);
    begin++;
    end--;
  }
}

void Print(vector<int>& arr)
{
  cout<<"[";
  for(auto e : arr)
  {
    cout<<e<<" ";
  }
  cout<<"]"<<endl;
}

void TestSelect()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  Select(arr);
  Print(arr);
}

void Insert(vector<int>& arr)
{
  for(size_t i = 1;i < arr.size();i++)
  {
    int temp = arr[i];//保存当前元素
    int j;
    for(j = i;j > 0;j--)//循环遍历i之前的元素
    {
      if(temp < arr[j - 1])//如果出现当前元素比前面的元素小，就把前面的元素往后挪
      {
        arr[j] = arr[j - 1];
      }
      else 
      {
        break;
      }
    }

    //把保存的元素放到合适的位置
    arr[j] = temp;
  }
}

void TestInsert()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  Insert(arr);
  Print(arr);
}

void ShellSort(vector<int> str)
{
  int len = str.size();
  int i = 0;
  int j = 0;
  int k = 0;
  int temp;
  int gap = len / 2 + 1;//gap不仅是增量还是分得的组数
  for (;gap>0;gap/=2)
  {
    for (k = 0;k < gap;k++)
    {
      for (i = k+gap; i < len; i += gap)
      {
        temp = str[i];
        for (j = i;j > 0 && str[j - gap] > temp;j-=gap)
        {
          str[j] = str[j - gap];
        }
        str[j] = temp;
      }
    }
  }
}
void TestShell()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  ShellSort(arr);
  Print(arr);
}

//向下调整
void adjustdown(vector<int>& arr, int begin,int end)
{
  //父亲节点
  int parent = begin;
  //孩子节点，* 2 + 1 和 * 2 + 2；
  int child = parent * 2 + 1;

  //一直向下到最后一层节点
  while(child < end)
  {
    //如果左孩子比右孩子小，进行行交换
    if(child + 1 < end && arr[child + 1] > arr[child])
    {
      child = child + 1;
    }

    //如果孩子比父亲大进行交换
    if(arr[child] > arr[parent])
    {
      swap(arr[child],arr[parent]);
      parent = child;
      child = parent * 2 + 1;
    }
    else 
    {
      break;
    }
  }
}

void Heap(vector<int>& arr)
{
  //把整棵树调整为大根堆
  for(int i = (arr.size() - 1 - 1) >> 1;i >= 0;i-- )
  {
    adjustdown(arr,i,arr.size());
  }

  //每次把堆顶元素和最后一个元素交换
  int end = arr.size() - 1;
  while(end > 0)
  {
    swap(arr[0],arr[end]);
    end--;

    //把元素个数--后再向下调整，相当于最后一个元素已经有序不参与调整
    adjustdown(arr,0,end);
  }

}

void TestHeap()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  Heap(arr);
  Print(arr);
}

void bubbleSort(vector<int>& arr)
{
  for(int i = 0;i < arr.size() - 1;i++)
  {
    for(int j = 0;j < arr.size() - 1 - i;j++)
    {
      if(arr[j] > arr[j + 1])
      {
        swap(arr[j],arr[j + 1]);
      }
    }
  }
}
void TestBubble()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  bubbleSort(arr);
  Print(arr);
}

int QuickChild(vector<int>& arr,int begin,int end)
{
  int key = arr[begin];
  while(begin < end)
  {
    while(begin < end && arr[end] >= key)
    {
      end--;
    }
    //arr[begin] = arr[end];
    while(begin < end && arr[begin] <= key)
    {
      begin++;
    }
    swap(arr[begin],arr[end]);
    //arr[end] = arr[begin];
  }
  swap(arr[end],key);
  //arr[begin] = key;
  return begin;
}

void Quick(vector<int>& arr,int begin,int end)
{
  if(begin < end)
  {
    int mid = QuickChild(arr,begin,end);
    Quick(arr,begin,mid - 1);
    Quick(arr,mid + 1,end);

  }
}

void TestQuick()
{
  vector<int> arr {3,1,6,4,7,4,1,99,7,4,3,-8};
  Quick(arr,0,11);
  Print(arr);
}

int main()
{
  TestSelect();
  TestInsert();
  //TestShell();
  TestHeap();
  TestBubble();
  TestQuick();
  return 0;
}
