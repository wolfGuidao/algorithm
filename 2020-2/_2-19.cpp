#include "Header.hpp"

//滑动窗口
//1.
string minWindow(string s, string t) 
{
  unordered_map<char,int> _win;
  unordered_map<char,int> _need;
  int start = 0;
  int minLen = INT_MAX;
  int right = 0;
  int left = 0;

  for(auto e : t)
  {
    _need[e]++;
  }

  int matchcount = 0;
  while(right < s.size())
  {
    char ch = s[right];
    if(_need.count(ch))
    {
      _win[ch]++;
      if(_win[ch] = _need[ch])
      {
        matchcount++;
      }
    }

    right++;

    while(matchcount == _need.size())
    {
      if(minLen > right - left)
      {
        minLen = right - left;
        start = left;
      }

      char ch = s[left];

      if(_need.count(ch))
      {
        _win[ch]--;
        if(_win[ch] < _need[ch])
        {
          matchcount--;
        }
      }
      left++;
    }
  }
  return minLen == INT_MAX ?
                    "" : s.substr(start, minLen);
}

//2.
int lengthOfLongestSubstring(string s) {
  int right = 0;
  int left = 0;
  int ret = INT_MIN;

  unordered_map<char,int> win;
  while(right < s.size())
  {
    char ch = s[right];
    win[ch]++;
    right++;

    while(win[ch] > 1)
    {
      char cch = s[left];
      win[cch]--;
      left++;
    }
    ret = max(ret,right - left);
  }
  return ret;
}

int main()
{
  string s {"ADOBECODEBANC"};
  string t {"BBBBB"};
  cout<<minWindow(s,t)<<endl;
  cout<<lengthOfLongestSubstring(t)<<endl;
  return 0;
}
