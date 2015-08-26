class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum ^= (i+1);
            sum ^= nums[i];
        }
        /*
        int sum = (n & 1) ? n * ((n+1) >> 1) : (n >> 1) * (n+1);
        for (int i = 0; i < n; ++i) {
            sum -= nums[i];
        }
        */
        return sum;
    }
};
