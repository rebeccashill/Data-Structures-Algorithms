#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* longestValidParentheses (Leetcode Solution)
    Parameters: string s (string of parentheses)
    Method: dynamic programming
    1. Initialize variable for string size, max length, and dp vector.
    2. Loop through the string.
    3. If s[i] and s[i-1] is "()", append to the dp array. Else, do not.
    4. Update max length.
    5. Exit for loop and return max length.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int strSize = s.size();
        vector<int> dp(strSize, 0);
        int maxLength = 0;

        for (int i = 1; i < strSize; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }
};
