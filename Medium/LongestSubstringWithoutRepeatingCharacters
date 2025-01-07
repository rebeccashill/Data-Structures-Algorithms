//Sliding Window (optimized)
//Runtime: 8 ms, faster than 93.51% of C++ online submissions on Leetcode for Longest Substring Without Repeating Characters.
//Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions on Leetcode for Longest Substring Without Repeating Characters.
//time: O(N), space: O(size_of_charset)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> position(128, -1);
        int ans = 0;
        
        for(int i = 0, j = 0; j < n; j++){
            if(position[s[j]] != -1){
                i = max(i, position[s[j]]+1);
            }
            ans = max(ans, j-i+1);
            position[s[j]] = j;
        }
        
        return ans;
    }
};
