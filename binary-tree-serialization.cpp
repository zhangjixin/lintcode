/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        stringstream ss;
        doSerialize(root, ss);
        return ss.str();
    }
    void doSerialize(TreeNode *root, stringstream &ss) {
        if (root == NULL) {
            ss << '#';
            return;
        }
        ss << root->val << ',';
        doSerialize(root->left, ss);
        doSerialize(root->right, ss);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        stack<TreeNode*> que;
        int n = data.size();
        if (n < 3 ) return NULL;
        bool flag = false;
        int i = 0, num = 0;
        while (data[i] != ',') 
            num = num * 10 + (data[i++] - '0');
        TreeNode *root = NULL, *p = new TreeNode(data[0]-'0'), *head = p;
        que.push(p);
        for (i = i + 1; i < n ; ++i) {
            root = que.top(), num = 0;
            if (data[i] == '#') {
                if (!flag) {
                    flag = true;
                } else {
                    que.pop();
                }
            }
            else {
                while (data[i] != ',') 
                    num = num*10 + (data[i++] - '0');
                p = new TreeNode(num);
                if (!flag) {
                    root->left = p;
                    que.push(p);
                }
                else {
                    root->right = p;
                    que.pop();
                    que.push(p);
                    flag = false;
                }
            }
        }
        return head;
    }
};

//solution 2:
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        stringstream ss;
        doSerialize(root, ss);
        return ss.str();
    }
    void doSerialize(TreeNode *root, stringstream &ss) {
        if (root == NULL) {
            ss << '#';
            return;
        }
        ss << root->val << ',';
        doSerialize(root->left, ss);
        doSerialize(root->right, ss);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *doDeserialize(string data, int &i) {
        
        int num = 0, n = data.size();
        if (i >= n || data[i] == '#') {
            i += 1;
            return NULL;
        }
        while (data[i] != ',' && i < n) 
            num = num * 10 + (data[i++] - '0');
        i += 1;
        TreeNode *p = new TreeNode(num);
        p->left = doDeserialize(data, i);
        p->right = doDeserialize(data, i);
        return p;
    }
    TreeNode *deserialize(string data) {
        // write your code here
        if (data.size() < 3 ) return NULL;
        int i = 0;
        return doDeserialize(data, i);
    }
};