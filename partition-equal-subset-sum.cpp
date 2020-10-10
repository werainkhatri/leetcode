#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
Brute Force:

bool partition(vector<int> nums, int totalSum, int sum, int i)
{
    if (i == nums.size())
        return false;
    return sum * 2 == totalSum ||
           partition(nums, totalSum, sum + nums[i], i + 1) ||
           partition(nums, totalSum, sum, i + 1);
}
*/

/*
DP: SLOWER

bool partition(vector<int> nums, int totalSum, int sum, int i, map<string, bool> &memo)
{
    string current = to_string(i) + " " + to_string(sum);
    if (memo[current] != NULL)
        return memo[current];
    bool result;
    if (i >= nums.size() || sum * 2 > totalSum)
        result = false;
    else if (sum * 2 == totalSum)
        result = true;
    else
        result = partition(nums, totalSum, sum, i + 1, memo) ||
                 partition(nums, totalSum, sum + nums[i], i + 1, memo);
    memo[current] = result;
    return result;
}
*/

// BottomUp: FASTER
bool subsetSum(vector<int> nums, int sum)
{
    bool subsetSum[nums.size() + 1][sum + 1];

    for (int j = 0; j < sum + 1; j++)
        subsetSum[0][j] = false;

    for (int i = 0; i < nums.size() + 1; i++)
        subsetSum[i][0] = true;

    for (int i = 1; i < nums.size() + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (j < nums[i - 1])
                subsetSum[i][j] = subsetSum[i - 1][j];
            else if (j == nums[i - 1])
                subsetSum[i][j] = true;
            else
                subsetSum[i][j] = subsetSum[i - 1][j - nums[i - 1]] || subsetSum[i - 1][j];
        }

    return subsetSum[nums.size()][sum];
}

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (int i : nums)
        totalSum += i;
    if (totalSum % 2 != 0)
        return false;

    map<string, bool> memo;
    return subsetSum(nums, totalSum / 2);
}

int main()
{
    vector<int> vect{3, 3, 3, 4, 5};
    if (canPartition(vect))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}