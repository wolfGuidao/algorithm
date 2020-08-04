/*************************************************************************
# File Name: 8-14.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月31日 星期五 09时50分59秒
 *************************************************************************/
#include <iostream>
#include <stack>
using namespace  std;

#if 0
int main()
{
    stack<int> s1;
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    stack<int> s2;
    int temp1 = s1.top();
    s1.pop();
    int temp2 = s2.top();
    s2.pop();

    while(!s1.empty())
    {
        if(temp1 >= temp2)
        {
            s2.push(temp1);
            if(!s1.empty())
            {
                temp1 = s1.top();
                s1.pop();
            }
        }
        else 
        {
            s2.push(temp2);
            if(!s1.empty())
            {
                temp2 = s1.top();
                s1.pop();
            }
        }
    }

    temp1 = s2.top();
    s2.pop();
    temp2 = s2.top();
    s2.pop();

    while(!s2.empty())
    {
        if(temp1 >= temp2)    
        {    
            s1.push(temp2);    
            if(!s2.empty())    
            {    
                temp2 = s2.top();    
                s2.pop();    
            }    
        }    
        else     
        {    
            s1.push(temp1);    
            if(!s2.empty())    
            {    
                temp1 = s2.top();    
                s2.pop();    
            }    
        }    

    }

    while(!s1.empty())
    {
        cout<<s1.top()<<" : ";
    }
    cout<<endl;
    return 0;
}
#endif

#if 0
int main()
{
    return 0;
}

class Solution {
    public:
        int GetSum(int index_x,int index_y)
        {
            int sum = 0;
            while(index_x)
            {
                int temp = index_x % 10;
                index_x = index_x / 10;
                sum += temp;
            }

            while(index_y)
            {
                int temp = index_y % 10;
                index_y = index_y / 10;
                sum += temp;
            }

            return sum;
        }

        int count = 0;

        void help(int m,int n,int k,int x,int y,vector<vector<int>>& visted)
        {
            if(x < 0 || x >= m || y < 0 || y >= n || GetSum(x,y) > k || visted[x][y])
            {
                return ;
            }

            visted[x][y] = 1;
            count++;
            help(m,n,k,x + 1,y,visted);
            help(m,n,k,x - 1,y,visted);
            help(m,n,k,x,y + 1,visted);
            help(m,n,k,x,y - 1,visted);
        }

        int movingCount(int m, int n, int k) {
            if(m == 0 && n == 0)
            {
                return 0;
            }

            vector<vector<int>> visted(m,vector<int>(n,0));

            help(m,n,k,0,0,visted);

            return count;
        }
};
#endif 

// adjacent_find example
#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector

bool myfunction (int i, int j) {
    return (i < j);
}

#include <array>
int main () {
    //int myints[] = {5,20,5,30,30,20,10,10,20};
    //std::vector<int> myvector (myints,myints+8);
    //std::vector<int>::iterator it;

    // using default comparison:
    //it = std::adjacent_find (myvector.begin(), myvector.end());

    //if (it!=myvector.end())
    //  std::cout << "the first pair of repeated elements are: " << *it << '\n';

    //using predicate comparison:
    //it = std::adjacent_find (myvector.begin(), myvector.end(), [](int a,int b)
    //        {
    //          return a < b;
    //        });

    //if (it!=myvector.end())
    //  std::cout << "the second pair of repeated elements are: " << *it << '\n';

    //  std::array<int,8> foo = {3,5,7,11,13,17,19,20};

    //if ( std::any_of(foo.begin(), foo.end(), [](int i){return i%2;}) )
    //  std::cout << "All the elements are odd numbers.\n";
    //else 
    //{
    //    cout<<"not ALL"<<endl;
    //}

    //int myints[] = {1,2,3,4,5,4,3,2,1};
    //std::vector<int> v(myints,myints+9); // 1 2 3 4 5 4 3 2 1

    //// using default comparison:
    //std::sort (v.begin(), v.end());

    //std::cout << "looking for a 3... ";
    //if (std::binary_search (v.begin(), v.end(), 9))
    //    std::cout << "found!\n"; 
    //else 
    //    std::cout << "not found.\n";

    //// using myfunction as comp:
    ////std::sort (v.begin(), v.end());

    //std::cout << "looking for a 6... ";
    //if (std::binary_search (v.begin(), v.end(), 3, [](int a,int b)
    //            {
    //                return a > b;
    //            }))
    //    std::cout << "found!\n"; 
    //else 
    //    std::cout << "not found.\n";

  //  int myints[]={10,20,30,40,50,60,70};
  //std::vector<int> myvector (7);

  //auto e = std::copy_backward ( myints, myints+7, myvector.end());

  //cout<<*(--e)<<endl;

  //std::cout << "myvector contains:";
  //for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  //  std::cout << ' ' << *it;

  //std::cout << '\n';

  ////  myvector.resize(myvector.size() + 3);

  ////copy_backward(myvector.begin(),myvector.end(),myvector.end());
  ////std::cout << "myvector contains:";
  ////for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  ////  std::cout << ' ' << *it;

  ////std::cout << '\n';

  //  int myints[]={10,20,30,40,50,60,70};
  //std::vector<int> myvector;

  //myvector.resize(9);   // allocate space for 7 elements

  //std::copy_n ( myints, 9, myvector.begin() );

  //std::cout << "myvector contains:";
  //for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
  //  std::cout << ' ' << *it;

  //std::cout << '\n';

    int myints[] = {20,40,60,80,100,111,111,111};               //   myints: 20 40 60 80 100
  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  // using default comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  //myvector[3]=81;   // myvector: 20 40 60 81 100

  // using predicate comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints, [](int a,int b)
              {
                return a == b;
              }) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";


    return 0;
}
