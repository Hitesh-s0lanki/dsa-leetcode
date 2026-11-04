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

TreeNode *buildTree(vector<int> arr, int &i) {
    // base case
    if (arr[i] == -1) {
        i++;
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[i++]);

    root->left = buildTree(arr, i);
    root->right = buildTree(arr, i);

    return root;
}

void preOrder(TreeNode *root) {
    if (root == NULL)
        return;

    cout << root->val << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    preOrder(root->left);
    cout << root->val << "\t";
    preOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << "\t";
}

class Solution {
public:
    pair<int, int> solve(TreeNode *root, int &cnt) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = solve(root->left, cnt);
        pair<int, int> right = solve(root->right, cnt);

        int average = (root->val + left.first + right.first) / (1 + left.second + right.second);

        if (average == root->val)
            cnt++;

        return make_pair(root->val + left.first + right.first, 1 + left.second + right.second);
    }

    int averageOfSubtree(TreeNode *root) {
        int cnt = 0;

        solve(root, cnt);

        return cnt;
    }
};

int main() {
    // vector<int> val = {4, 8, 0, -1, -1, 1, -1, -1, 5, -1, 6, -1, -1};
    vector<int> val = {1, -1, -1};
    int index = 0;

    TreeNode *root = buildTree(val, index);

    // preOrder(root);

    Solution st;
    cout << st.averageOfSubtree(root);

    return 0;
}