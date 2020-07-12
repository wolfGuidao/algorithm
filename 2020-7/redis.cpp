/*************************************************************************
    > File Name: redis.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月11日 星期六 22时13分05秒
 ************************************************************************/

#include "redis.hpp"
 
int main()
{
	Redis *r = new Redis();
	if(!r->connect("127.0.0.0", 6379))
	{
		printf("connect error!\n");
		return 0;
	}
	r->set("name", "Mayuyu");
	printf("Get the name is %s\n", r->get("name").c_str());
	delete r;
	return 0;
}
