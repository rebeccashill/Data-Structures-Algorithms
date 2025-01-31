class Solution {
public:

    vector<vector<int>>dp;

    bool solve(string &s, string &p, int i, int j){

        if(j == p.length()) return i == s.length();

        if(dp[i][j] != -1) return dp[i][j];

        bool isCharMatch = false;

        if(i < s.length() && (p[j] == s[i] || p[j] == '.')) isCharMatch = true;

        if(p[j+1] == '*'){
            bool not_take = solve(s, p, i, j+2);
            bool take = isCharMatch && solve(s, p, i+1, j);

            return dp[i][j] = take || not_take;
        }

        return dp[i][j] = isCharMatch && solve(s, p, i+1, j+1);
    }

    bool isMatch(string s, string p) {
        
        dp.resize(s.length()+1, vector<int>(p.length() +1, -1));
        return solve(s, p, 0, 0);
    }
};
