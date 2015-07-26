class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        int len = A.size(), cnt = 0;
        int id = -1,  retLen = len - k;
        bool firstCh = true;
        stringstream strs;
        while (cnt < retLen ) {
            if (k == 0) {
                for (int i = id + 1; i < len; ++i)
                    strs << A[i];
                break;
            }
            char minCh = A[id + 1] + 1;
            int tempId = id + 1;
            for (int i = tempId; i <= tempId + k; ++i) {
                if (A[i] < minCh) {
                    minCh = A[i];
                    id = i;
                }
            }
            if (firstCh && minCh != '0') {
                strs << minCh;
                firstCh = false;
            }
            else if (!firstCh) {
                strs << minCh;
            }
            ++cnt;
            k -= id - tempId;
        }
        return strs.str();
    }
};

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        vector<char> vec;
        int len = A.size(), i = 0;
        for (i = 0; i < len; ++i) {
            if (vec.empty() || A[i] >= vec.back() || k <= 0) {
                vec.push_back(A[i]);
                continue;
            }
            if (A[i] < vec.back()) {
                vec.pop_back();
                --i;
                --k;
            }
        }
        while (k-- > 0) {
            vec.pop_back();
        }
        len = vec.size(), i = 0;
        stringstream strs;
        while (vec[i] == '0') ++i;
        while (i < len) strs << vec[i++];
        return strs.str();
    }
};

