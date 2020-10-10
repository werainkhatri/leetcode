#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
    int len = s.length();
    if (len <= 1)
        return s;
    int si = 0, slen = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (slen > (len - i) * 2)
            return s.substr(si, slen);
        int front = i, end = i;
        // counting all repeating chars together
        while ((end < len - 1) && s[i] == s[end + 1])
            end++;
        // expanding on b/s
        while (front > 0 && end < len - 1 && s[front - 1] == s[end + 1])
        {
            front--;
            end++;
        }
        if (slen < (end - front + 1))
        {
            si = front;
            slen = end - front + 1;
        }
    }
    return s.substr(si, slen);
}

int main()
{
    cout << longestPalindrome("abcdefedxyz") << endl;
    return 0;
}