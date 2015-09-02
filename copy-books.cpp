class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int left = pages[0], right = 0, mid = 0;
        int n = pages.size();
        for (int i = 0; i < n; ++i) {
            right += pages[i];
        }
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            int tempK = k, j = 0, cnt = 0;
            
            while (tempK > 0 && j < n) {
                cnt += pages[j];
                if (cnt < mid) {
                    ++j;
                }
                else {
                    --tempK;
                    j += (cnt == mid ? 1 : 0);
                    cnt = 0;
                }
            }
            if (tempK > 0 || (tempK == 0 && j == n)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
