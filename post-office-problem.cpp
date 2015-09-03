class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
     // w[i][j] is the cost of range[i, j] when i is the post office
     // so the cost of range[i, j] is w[(i+j)/2][i] + w[(i+j)/2][j]
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int n = A.size(), idx = 0, minval = 0, temp = 0;
        if (n < 1 || k >= n) return 0;
        sort(A.begin(), A.end());
        vector<vector<int>> dp(n, vector<int>(k, 0)), w(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                w[i][j] = w[i][j-1] + A[j] - A[i];
            }
            for (int j = i - 1; j >= 0; --j) {
                w[i][j] = w[i][j+1] + A[i] - A[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = costI2J(0, i, w);//w[0][idx] + w[idx][i];
        }
        for (int j = 1; j < k; ++j) {
            for (int i = j + 1; i < n; ++i) {
                minval = dp[n-1][0];
                for (int k = j-1; k < i; ++k) {
                    temp = dp[k][j-1] + costI2J(k+1, i, w);
                    if (temp < minval) {
                        minval = temp;
                    }
                }
                dp[i][j] = minval;
            }
        }
        return dp[n-1][k-1];
    }
    int costI2J(int i, int j, const vector<vector<int>> &w) {
        int k = (i + j) >> 1;
        return w[k][i] + w[k][j];
    }
};
