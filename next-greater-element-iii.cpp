#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int nextGreaterElement(int n) {
    vector<int> digits;
    long answer = 0;
    digits.push_back(n%10);
    n /= 10;
    int posSwapped = -1;
    while (n>0) {
        if (digits.back() > n%10 && posSwapped == -1) {
            int x = 1;
            while (true) {
                if (digits.end() - x + 1 == digits.begin() || n%10 >= *(digits.end() - x)) {
                    int v = *(digits.end() - x + 1);
                    digits.erase(digits.end() - x + 1);
                    x = v;
                    break;
                }
                else x++;
            }
            digits.push_back(n%10);
            digits.push_back(x);
            posSwapped = digits.size() - 1;
        }
        else
            digits.push_back(n%10);
        n /= 10;
    }
    if (posSwapped == -1) return -1;
    sort(digits.begin(), digits.begin() + posSwapped, greater<int>());
    while (!digits.empty()) {
        answer = answer * 10 + digits.back();
        digits.pop_back();
    }
    if (answer <= INT32_MAX) return (int)answer;
    return -1;
}

int main()
{
    int x;
    cin >> x;
    cout << nextGreaterElement(x) << endl;
    return 0;
}