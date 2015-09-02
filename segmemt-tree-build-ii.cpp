/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return buildTree(0, A.size() - 1, A);
    }
    SegmentTreeNode* buildTree(int left, int right, const vector<int>& A) {
        if (left > right) return NULL;
        SegmentTreeNode *node = new SegmentTreeNode(left, right, A[left]);
        if (left < right) {
            int mid = (left + right) >> 1;
            node->left = buildTree(left, mid, A);
            node->right = buildTree(mid+1, right, A);
            if (node->left != NULL && node->left->max > node->max)
                node->max = node->left->max;
            if (node->right != NULL && node->right->max > node->max)
                node->max = node->right->max;
        }
        return node;
    }
};
