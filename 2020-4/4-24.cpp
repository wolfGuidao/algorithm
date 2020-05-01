#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  int n, m;
  cin >> n;

  int len;
  pair<int, int> xy;

  while (n--)
  {
    cin >> m;

    int count = 0;
    map<pair<int, int>, int> preFeaTimes;
    map<pair<int, int>, int> feaTimes;
    while (m--)
    {
      cin >> len;
      for (int i = 0; i < len; i++)
      {
        cin >> xy.first >> xy.second;

        if (preFeaTimes.count(xy))
          feaTimes[xy] = preFeaTimes[xy] + 1;
        else
          feaTimes[xy] = 1;

        count = max(count,feaTimes[xy]);


      }
      preFeaTimes.clear();
      preFeaTimes.swap(feaTimes);

    }
    cout << count << endl;

  }

  return 0;

}
