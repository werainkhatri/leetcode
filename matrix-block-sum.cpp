#include <vector>
#include <iostream>
#include <map>

using namespace std;

/*
Brute Force:

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
           vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
                for (int x = max<int>(i - K, 0); x < min<int>(i + K + 1, mat.size()); x++)
                    for (int y = max<int>(j - K, 0); y < min<int>(j + K + 1, mat[x].size()); y++)
                            answer[x][y] += mat[i][j];
        return answer;
    }
*/

// DP:
vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
{
    vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), 0));
    map<string, int> prefixSum;

    for (int i = 0; i < mat.size(); i++)
    {
        int rowPrefixSum = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            string key = to_string(i) + " " + to_string(j);
            int upperPrefixSum = 0;
            if (i > 0)
            {
                string upperRowKey = to_string(i - 1) + " " + to_string(j);
                upperPrefixSum = prefixSum[upperRowKey];
            }
            prefixSum[key] = upperPrefixSum + rowPrefixSum + mat[i][j];
            rowPrefixSum += mat[i][j];
        }
    }

    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
        {
            int wholeSum = prefixSum[to_string(min<int>(i + K, mat.size() - 1)) + " " + to_string(min<int>(j + K, mat[i].size() - 1))];
            int leftSum = prefixSum[to_string(min<int>(i + K, mat.size() - 1)) + " " + to_string(max<int>(j - K - 1, -1))];
            int topSum = prefixSum[to_string(max<int>(i - K - 1, -1)) + " " + to_string(min<int>(j + K, mat[i].size() - 1))];
            int topLeftSum = prefixSum[to_string(max<int>(i - K - 1, -1)) + " " + to_string(max<int>(j - K - 1, -1))];
            answer[i][j] = wholeSum - leftSum - topSum + topLeftSum;
        }
    return answer;
}

int main()
{
    // vector<vector<int>> mat{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> mat{{67, 64, 78}, {99, 98, 38}, {82, 46, 46}, {6, 52, 55}, {55, 99, 45}};
    // vector<vector<int>> mat{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int k;
    cin >> k;
    vector<vector<int>> answer = matrixBlockSum(mat, k);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}