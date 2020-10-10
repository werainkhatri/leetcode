#include <bits/stdc++.h>

using namespace std;

int recurssion(int i, int j, int obs, vector<vector<int>> grid)
{
    if (grid[i][j] == -1)
        return 0;
    if (grid[i][j] == 2)
    {
        if (obs + 1 == grid.size() * grid[0].size())
            return 1;
        else
            return 0;
    }
    int count = 0;
    grid[i][j] = -1;
    if (i > 0)
        count += recurssion(i - 1, j, obs + 1, grid); // up
    if (j > 0)
        count += recurssion(i, j - 1, obs + 1, grid); // left
    if (i < grid.size() - 1)
        count += recurssion(i + 1, j, obs + 1, grid); // down
    if (j < grid[0].size() - 1)
        count += recurssion(i, j + 1, obs + 1, grid); // right
    return count;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int x, y, obs = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
            else if (grid[i][j] == -1)
                obs++;
        }
    }
    return recurssion(x, y, obs, grid);
}

int main()
{
    vector<vector<int>> grid{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << uniquePathsIII(grid) << endl;
    return 0;
}