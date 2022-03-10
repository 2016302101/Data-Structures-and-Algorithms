/*
    构造一个简单的二叉树，可以实现树初始化，三种常规遍历方式的递归和迭代
    中序遍历和后序遍历的迭代参考labuladong的模板
    https://labuladong.gitee.io/algo/2/19/34/
 */

#include <iostream>
#include <stack> 
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(): val(0){};
        TreeNode(int num): val(num) {};
        TreeNode(int num, TreeNode* left, TreeNode* right): val(num), left(left), right(right) {};
};


// 二叉树的初始化函数（使用前序遍历进行初始化）
TreeNode* Create_BinaryTree() {
    TreeNode* root = new TreeNode;
    int val;
    cin >> val;
    // 如何解决这个安全问题？
    if (val == -1) {
        return nullptr;
    }
    else {
        root -> val = val;
        root -> left = Create_BinaryTree();
        root -> right = Create_BinaryTree();
    }
    return root;
}

// 二叉树的前序遍历 - 递归实现
void Preorder1(vector<int>& nums, TreeNode* root) {
    if (root == nullptr)
        return;
            
    nums.emplace_back(root -> val);
    Preorder1(nums, root -> left);
    Preorder1(nums, root -> right);
}

// 二叉树的前序遍历 - 迭代实现
void Preorder2(vector<int>& nums, TreeNode* root) {
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()) {
        auto cur = stk.top();
        stk.pop();
        nums.emplace_back(cur -> val);

        if (cur -> right != nullptr)
            stk.push(cur -> right);
        if (cur -> left != nullptr)
            stk.push(cur -> left);
    }
}

// 二叉树的中序遍历 - 递归实现
void Inorder1(vector<int>& nums, TreeNode* root) {
    if (root == nullptr)
        return;
            
    Inorder1(nums, root -> left);
    nums.emplace_back(root -> val);
    Inorder1(nums, root -> right);
}

// 一直向左撸到底
void pushLeftBranch(stack<TreeNode*>& stk ,TreeNode* root) {
    while(root != nullptr) {
        stk.push(root);
        root = root -> left;
    }
}

// 二叉树的中序遍历 - 迭代实现
void Inorder2(vector<int>& nums, TreeNode* root) {
    stack<TreeNode*> stk;
    pushLeftBranch(stk, root);

    TreeNode* visit = new TreeNode(-1);
    while(!stk.empty()) {
        auto cur = stk.top();

        if ((cur -> left == nullptr || visit == cur -> left) && visit != cur -> right) {
            nums.emplace_back(cur -> val);
            pushLeftBranch(stk, cur -> right);
        }
        if (cur -> left == nullptr || visit == cur -> right) {
            visit = stk.top();
            stk.pop();
        }
    }
}

// 二叉树的后序遍历 - 递归实现
void Postorder1(vector<int>& nums, TreeNode* root) {
    if (root == nullptr)
        return;
            
    Postorder1(nums, root -> left);
    Postorder1(nums, root -> right);
    nums.emplace_back(root -> val);
}

// 二叉树的后序遍历 - 迭代实现
void Postorder2(vector<int>& nums, TreeNode* root) {
    stack<TreeNode*> stk;
    pushLeftBranch(stk, root);

    TreeNode* visit = new TreeNode(-1);
    while(!stk.empty()) {
        auto cur = stk.top();
        nums.emplace_back(cur -> val);
        if ((cur -> left == nullptr || visit == cur -> left) && visit != cur -> right) {
            pushLeftBranch(stk, cur -> right);
        }
        if (cur -> left == nullptr || visit == cur -> right) {
            // nums.emplace_back(cur -> val);
            visit = stk.top();
            stk.pop();
        }
    }
}

int main() {
    // demo : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    TreeNode* root = Create_BinaryTree();
    vector<int> nums;
    // Preorder1(nums, root);
    // Preorder2(nums, root);
    // Inorder1(nums, root);
    // Inorder2(nums, root);
    // Postorder1(nums, root);
    // Postorder2(nums, root);
    return 0;
};