#include <bits/stdc++.h>

using namespace std;

int minAreaRect(vector<vector<int>> &points)
{
  int minArea = INT_MAX;
  unordered_map<int, set<int>> x;
  for (vector<int> p : points)
    x[p[0]].insert(p[1]);
  for (auto i = x.begin(); i != x.end(); i++)
    for (auto j = next(i); j != x.end(); j++)
    {
      if (i->second.size() < 2 || j->second.size() < 2)
        continue;
      vector<int> y;
      set_intersection(begin(i->second), end(i->second), begin(j->second), end(j->second), back_inserter(y));
      for (int k = 1; k < y.size(); k++)
      {
        int area = abs(j->first - i->first) * (y[k] - y[k - 1]);
        if (area < minArea)
          minArea = area;
      }
    }
  return minArea == INT_MAX ? 0 : minArea;
}

int main()
{
  vector<vector<int>> points{{0, 1}, {0, 0}, {1, 0}, {1, 1}};
  cout << minAreaRect(points) << endl;
  return 0;
}