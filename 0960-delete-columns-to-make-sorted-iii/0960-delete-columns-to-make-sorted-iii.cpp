class Solution {
public:
    int minDeletionSize(vector<string>& strs) {// Using DP
        int n = strs.size();          // number of strings (rows)
        int m = strs[0].size();       // length of each string (columns)

        // dp[j] = length of longest valid subsequence ending at column j
        vector<int> dp(m, 1);         
        int maxKeep = 1;              // maximum number of columns we can keep

        // Outer loop: consider each column j
        for (int j = 0; j < m; j++) {
            // Inner loop: try to extend subsequence from column i to column j
            for (int i = 0; i < j; i++) {
                bool valid = true;

                // Check all rows: column i must not break order before column j
                for (int r = 0; r < n; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        valid = false;
                        break;
                    }
                }

                // If valid, update dp[j] using dp[i]
                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            // Track the longest subsequence found so far
            maxKeep = max(maxKeep, dp[j]);
        }

        // Minimum deletions = total columns - longest subsequence length
        return m - maxKeep;
    }
};
