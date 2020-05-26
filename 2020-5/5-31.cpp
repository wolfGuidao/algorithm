#include "Header.hpp"

string MinWindow(string s, string t)
{
  int left = 0;
  int right = 0;
  int ret = INT_MAX;

  int start = 0;

  unordered_map<char,int> window;
  unordered_map<char,int> need;

  for (auto e : t)
  {
    need[e]++;
  }

  int matched = 0;
  while(right < s.size())
  {
    char ch = s[right];
    if(need.count(ch))
    {
      window[ch]++;
      if(need[ch] == window[ch])
      {
        matched++;
      }
    }

    right++;

    while(matched == need.size())
    {
      if(right - left < ret)
      {
        ret = right - left;
        start = left;
      }

      char ch = s[left];
      if(need.count(ch))
      {
        window[ch]--;
        if(window[ch] < need[ch])
        {
          matched--;
        }
      }
      left++;
    }
  }
  return ret == INT_MIN ? "" : s.substr(start,ret);
}

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout<<MinWindow(s, t)<<endl;
  return 0;
}
