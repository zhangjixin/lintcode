class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ret;
        int m = 0, n = 0, len = dictionary.size();
        for (int i = 0; i < len; ++i) {
            m = dictionary[i].size();
            if (m > n) {
                ret.clear();
                ret.push_back(dictionary[i]);
                n = m;
            } else if (m == n) {
                ret.push_back(dictionary[i]);
            }
        }
        return ret;
    }
};
