#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/* Longest Valid Parentheses in C++
 * 1. Initialize the size of the string
 * 2. Initialize a vector array called dp (representing that the problem is written with dynamic programming)
 * 3. Initialize the maxLength
 * 4. Loop through the array and compare to the value directly before to check to see if the values are opposite parentheses
 * */
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
        return maxLength;
    }
};
