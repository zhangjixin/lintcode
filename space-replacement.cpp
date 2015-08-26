class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int n = length;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ')
                n += 2;
        }
        int j = n - 1;
        for (int i = length - 1; i >= 0; --i) {
            if (string[i] == ' ') {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
            }
            else {
                string[j--] = string[i];
            }
        }
        return n;
    }
};  
