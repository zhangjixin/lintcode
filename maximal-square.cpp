class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(n,0));
        int idx = 0, ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[idx][j] = matrix[i][j];
                if (i && j && dp[idx][j]) {
                    dp[idx][j] = MIN(dp[idx^1][j], dp[idx][j-1], dp[idx^1][j-1]) + 1;
                }
                ans = max(ans, dp[idx][j]);
            }
            idx ^= 1;
        }
        return ans * ans;
    }
    inline int MIN(int a, int b, int c) {
        if (a <= b) 
            return a <= c ? a : c;
        return b <= c ? b : c;
    }
};








class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int cnt = 0, area = 0, k = min(m,n) - 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    matrix[i][j] += matrix[i-1][j];
                if (j > 0)
                    matrix[i][j] += matrix[i][j-1];
                if (i > 0 && j > 0)
                    matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        if (matrix[m-1][n-1] < 2)
            return matrix[m-1][n-1];
        while (k > 0) {
            area = (k+1) * (k+1);
            for (int i = m-1; i >= k; --i) {
                for (int j = n-1; j >= k; --j) {
                    cnt = matrix[i][j];
                    if (i > k)
                        cnt -= matrix[i-k-1][j];
                    if (j > k)
                        cnt -= matrix[i][j-k-1];
                    if (i > k && j > k) 
                        cnt += matrix[i-k-1][j-k-1];
                    if (cnt == area)
                        return area;
                }
            }
            --k;
        }
        return 1;
    }
};
