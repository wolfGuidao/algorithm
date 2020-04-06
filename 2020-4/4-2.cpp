#include "Header.hpp"
#include <boost/algorithm/string.hpp>

void TestSplit()
{
  vector<string> strout;
  string strstr = "https://www.baidu.com";

  boost::split(strout,strstr,boost::is_any_of("./"),boost::token_compress_on);
  for(auto e : strout)
  {
    cout<<e<<endl;
  }
  cout<<endl;
}

int main()
{
  TestSplit();
  return 0;
}
