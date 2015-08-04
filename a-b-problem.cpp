class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int both, either;
        while (a & b) {
            both = (a & b) << 1;
            either = a ^ b;
            a = both, b = either;
        }
        return a | b;
    }
};
