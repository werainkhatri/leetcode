#include <vector>
#include <iostream>
#include <map>

using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int count = 0;
    int buffer[matrix.size()][matrix[0].size()];

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (i == 0 || j == 0)
                buffer[i][j] = matrix[i][j];
            else {
                int x = min<int>(buffer[i][j-1], min<int>(buffer[i-1][j-1], buffer[i-1][j]));
                if (matrix[i][j] == 1) buffer[i][j] = x + 1;
                else buffer[i][j] = 0;
            }
            count += buffer[i][j];
        }
    }
    return count;
}

int main()
{
    // vector<vector<int>> matrix{ { 0, 0, 1 }, { 0, 1, 0 }, { 0, 1, 0 } };
    // vector<vector<int>> matrix{ { 0, 1, 1 }, { 0, 1, 1 }, { 0, 1, 1 } };
    // vector<vector<int>> matrix{ { 1, 0, 0 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 0, 1, 1 } };
    vector<vector<int>> matrix{
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << countSquares(matrix) << endl;
    return 0;
}