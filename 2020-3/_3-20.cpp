#include "Header.hpp"

int binaryLeft(vector<int>& arr,int target)
{
  int left = 0;
  int right = arr.size();

  while(left < right)
  {
    int mid = (left + right) >> 1;
    if(arr[mid] == target)
    {
      right = mid;
    }
    else if(arr[mid] < target)
    {
      left = mid + 1;
    }
    else 
    {
      right = mid;
    }
  }

  if(arr[left] == target)
  {
    return left;
  }
  return -1;
}

int binaryRight(vector<int>& arr,int target)
{
  int left = 0;
  int right = arr.size();

  while(left < right)
  {
    int mid = (left + right) >> 1;
    if(arr[mid] == target)
    {
      left = mid + 1;
    }
    else if(arr[mid] > target)
    {
      right = mid;
    }
    else 
    {
      left = mid + 1;
    }
  }

  if(left == 0)
  {
    return -1;
  }

  if(arr[left - 1] == target)
  {
    return left- 1;
  }
  return -1;
}

int main()
{
  vector<int> arr = {1,2,2,2,2,2,3,4,5};
  cout<<binaryLeft(arr,2)<<endl;
  cout<<binaryRight(arr,2)<<endl;
  return 0;
}
