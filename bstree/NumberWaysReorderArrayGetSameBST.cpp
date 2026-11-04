#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildBST(TreeNode *&root, int val) {
    if (root == NULL) {
        // create the new node
        TreeNode *temp = new TreeNode(val);
        root = temp;
        return;
    }

    // check the root
    if (root->val < val)
        buildBST(root->right, val);
    else
        buildBST(root->left, val);
}

void preOrder(TreeNode *root) {
    if (root == NULL)
        return;

    cout << root->val << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

int numOfWays(vector<int> &nums) {
    return 1;
}

int main() {
    vector<int> nums = {2, 1, 3};

    TreeNode *root = NULL;

    for (int num : nums)
        buildBST(root, num);

    preOrder(root);

    return 0;
}