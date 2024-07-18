

class Solution {
public:
    int helper(vector<string>& strs, int i, int m, int n,vector<vector<vector<int>>>& dp) {
        if (i == strs.size() || (m == 0 && n == 0)) {
            return 0;
        }
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int count0 = 0;
        int count1 = 0;
        for (int j = 0; j < strs[i].length(); j++) {
            if (strs[i][j] == '0') {
                count0++;
            } else if (strs[i][j] == '1') {
                count1++;
            }
        }
        
        int included = 0;
        if (count0 <= m && count1 <= n) {
            included = 1 + helper(strs, i + 1, m - count0, n - count1,dp);
        }
        
        int excluded = helper(strs, i + 1, m, n,dp);
        
         dp[i][m][n]=max(included, excluded);
         return dp[i][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
     vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, 0, m, n,dp);
    }
};
