#include "Header.hpp"
using namespace std;

void MergeSortChild(int* arr,int begin,int end,int* temp)
{
  if(begin == end)
  {
    return ;
  }
  int mid = (begin + end) >> 1;
  
  MergeSortChild(arr,begin,mid,temp);
  MergeSortChild(arr,mid + 1,end,temp);
  
  int begin1 = begin;
  int end1 = mid;
  int begin2 = mid + 1;
  int end2 = end;


  int index = begin;
  while(begin1 <= end1 && begin2 <= end2 )
  {
    if(arr[begin1] < arr[begin2])
    {
      temp[index] = arr[begin1];
      index++;
      begin1++;
    }
    else 
    {
      temp[index] = arr[begin2];
      index++;
      begin2++;
    }
  }
  while(begin1 <= end1)
  {
    temp[index] = arr[begin1];
    index++;
    begin1++;
  }
  while(begin2 <= end2)
  {
    temp[index] = arr[begin2];
    index++;
    begin2++;
  }

  memcpy(arr + begin,temp + begin,sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr,int n)
{
  int* temp = (int*)malloc(sizeof(int) * n);
  MergeSortChild(arr,0,n - 1,temp);
  for(int i = 0;i < n;i++)
  {
    cout<<arr[i]<<" < ";
  }
  cout<<endl;
}

int QuickChild(int* arr,int begin,int end)
{
  int key = arr[begin];
  while(begin < end)
  {
    while(begin < end && arr[end] > key)
    {
      end--;
    }
    arr[begin] = arr[end];

    while(begin < end && arr[begin] <= key)
    {
      begin++;
    }
    arr[end] = arr[begin];
  }
  arr[begin] = key;
  return begin;
}

void QuickSort(int* arr,int left,int right)
{
  stack<int> s;
  s.push(left);
  s.push(right);

  while(!s.empty())
  {
    int end = s.top();
    s.pop();
    int begin = s.top();
    s.pop();

    int mid = QuickChild(arr,begin,end);
    //cout<<"i am quicksort"<<endl;
    if(begin < mid - 1)
    {
      s.push(begin);
      s.push(mid - 1);
    }

    if(mid + 1 < end)
    {
      s.push(mid + 1);
      s.push(end);
    }
  }
  for(int i = 0;i <= right;i++)
  {
    cout<<arr[i]<<" < ";
  }
  cout<<endl;
}

int main()
{
  int arr[10] = {45,22,49,97,19,47,45,66,82,988};
  MergeSort(arr,10);
  int arr1[10] = {45,22,49,97,19,47,45,66,82,988};
  QuickSort(arr1,0,9);
  return 0;
}
