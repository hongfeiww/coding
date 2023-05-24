//
// Created by Gabrielle Wang on 2022/4/20.
//
#include <algorithm>
#include <iostream>
#include "tree.h"

namespace tree {

    void Tree::preOrderNonRecur(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        string res;
        stack<TreeNode *> s;
        s.emplace(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->right != nullptr) {
                s.emplace(node->right);
            }
            if (node->left != nullptr) {
                s.emplace(node->left);
            }
            res += to_string(node->val);
        }
        cout << res << endl;
        return;
    }

    void Tree::inOrderNonRecur(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        vector<int> res;
        stack<TreeNode *> s;
        s.emplace(root);
        TreeNode *node = s.top();
        while (!s.empty() || node != nullptr) {
            if (node != nullptr) {
                s.emplace(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                res.emplace_back(node->val);
                node = node->right;
            }
        }
        return;
    }

    void Tree::postOrderNonRecur(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return;
        }
        stack<TreeNode *> s;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        while (!s.empty() || node != nullptr) {
            if (node != nullptr) {
                s.emplace(node);
                node = node->left;
            } else {
                node = s.top();
                if (node->right != prev) {
                    node = node->right;
                } else {
                    s.pop();
                    res.emplace_back(node->val);
                    prev = node;
                    node = nullptr;
                }

            }
        }
    }

    int Tree::maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return std::max(left_height, right_height) + 1;
    }

    int Tree::diameterOfBinaryTree(TreeNode *root) {
        diameter = 0;
        depthOfBinaryTree(root);
        return diameter;
    }

    int Tree::depthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_length = depthOfBinaryTree(root->left);
        int right_length = depthOfBinaryTree(root->right);
        diameter = std::max(left_length + right_length, diameter);
        return std::max(left_length, right_length) + 1;
    }

    TreeNode *Tree::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return root;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        return root;
    }

    TreeNode *Tree::lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor2(root->left, p, q);
        TreeNode *right = lowestCommonAncestor2(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;

    }

    std::vector<std::vector<int>> Tree::pathSum(TreeNode *root, int target) {
        pathSumRecur(root, target);
        return paths;
    }

    void Tree::pathSumRecur(TreeNode *root, int target) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        target -= root->val;
        if (root->left == nullptr && root->right == nullptr && target == 0) { //leaf
            paths.emplace_back(path); //不能return，要回溯
        }
        pathSum(root->left, target);
        pathSum(root->right, target);
        path.pop_back();
    }

    bool Tree::verifyPostorder(std::vector<int> &postorder) {
        return verifyPostorderRecur(postorder, 0, postorder.size() - 1);
    }

    bool Tree::verifyPostorderRecur(std::vector<int> &postorder, int i, int j) {
        if (i >= j) {
            return true;
        }
        int mid_node = postorder[j];
        int k;
        for (k = i; k < j; k++) {
            if (postorder[k] > mid_node) {
                break;
            }
        }
        for (int t = k; t < j; t++) {
            if (postorder[t] < mid_node) {
                return false;
            }
        }
        return verifyPostorderRecur(postorder, i, k - 1) && verifyPostorderRecur(postorder, k, j - 1);
    }

    TreeNode *Tree::buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return buildTreeRecur(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *Tree::buildTreeRecur(vector<int> &preorder, int i, int j, vector<int> &inorder, int s, int t) {
        TreeNode *root = new TreeNode(preorder[i]);
        int k;
        for (k = s; k < t; k++) {
            if (inorder[k] == root->val) {
                break;
            }
        }
        //std::cout<<i<<" "<<j<<" " <<s<<" "<<t<<"k:"<<k;
        if (k > s) {
            root->left = buildTreeRecur(preorder, i + 1, i + k - s, inorder, s, k - 1);
        }
        if (k < t) {
            root->right = buildTreeRecur(preorder, i + 1 + k - s, j, inorder, k + 1, t);
        }
        return root;
    }

    int Tree::kthSmallest(TreeNode *root, int k) {
        kthSmallestRecur(root, k);
        return k_res;
    }

    void Tree::kthSmallestRecur(TreeNode *root, int k) {
        if (root == nullptr) {
            return;
        }
        kthSmallestRecur(root->left, k);
        seq++;
        if (seq == k) {
            k_res = root->val;
            return;
        }
        if (seq > k) {
            return;
        }
        kthSmallestRecur(root->right, k);
    }

    void Tree::flatten(TreeNode *root) {
        flattenRecur(root);
    }

    TreeNode *Tree::flattenRecur(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        //std::cout<<"root:"<<root->val;
        TreeNode *left_head = flattenRecur(root->left);
        //std::cout<<" l: "<<left_head;
        TreeNode *right_head = flattenRecur(root->right);
        //std::cout<<" r: "<<right_head;
        root->right = left_head;
        TreeNode *left_tail = root;
        while (left_tail->right != nullptr) {
            left_tail = left_tail->right;
        }
        left_tail->right = right_head;
        root->left = nullptr; //critical!
        return root;
    }

    TreeNode *Tree::connect(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        connectRecur(root->left, root->right);
        return root;
    }

    void Tree::connectRecur(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }
        node1->next = node2;
        connectRecur(node1->left, node1->right);
        connectRecur(node1->right, node2->left);
        connectRecur(node2->left, node2->right);
    }

    TreeNode *Tree::constructMaximumBinaryTree(vector<int> &nums) {
        TreeNode *root = constructMaximumBinaryTreeRecur(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode *Tree::constructMaximumBinaryTreeRecur(vector<int> &nums, int i, int j) {
        int idx = constructMaximumBinaryTreeFindMaxIdx(nums, i, j);
        if (idx < 0) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(nums[idx]);
        root->left = constructMaximumBinaryTreeRecur(nums, i, idx - 1);
        root->right = constructMaximumBinaryTreeRecur(nums, idx + 1, j);
        return root;
    }

    int Tree::constructMaximumBinaryTreeFindMaxIdx(vector<int> &nums, int i, int j) {
        int max_idx = -1;
        int max = -1;
        while (i <= j) {
            if (nums[i] > max) {
                max_idx = i;
                max = nums[i];
            }
            i++;
        }
        return max_idx;
    }

    vector<TreeNode *> Tree::findDuplicateSubtrees(TreeNode *root) {
        if (root == nullptr) {
            return sub_roots;
        }
        findDuplicateSubtreesRecur(root);
        return sub_roots;
    }

    string Tree::findDuplicateSubtreesRecur(TreeNode *root) {
        if (root == nullptr) {
            return string("#");
        }
        string left = findDuplicateSubtreesRecur(root->left);
        string right = findDuplicateSubtreesRecur(root->right);
        string res = left + "," + right + "," + to_string(root->val);
        sub_trees[res]++;
        if (sub_trees[res] == 2) {
            sub_roots.push_back(root);
        }
        return res;
    }

    TreeNode *Tree::bstToGst(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
        return root;
    }

    TreeNode *Tree::deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode *append_node = root->right;
            while (append_node->left != nullptr) {
                append_node = append_node->left;
            }
            append_node->left = root->left;
            return root->right;
        }
        return root;
    }

    vector<TreeNode *> Tree::generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> Tree::generateTrees(int s, int t) {
        if (s > t) {
            return {nullptr};
        }
        vector<TreeNode *> gen_trees;
        for (int i = s; i <= t; i++) {
            vector<TreeNode *> left = generateTrees(s, i - 1);
            vector<TreeNode *> right = generateTrees(i + 1, t);
            for (auto &l: left) {
                for (auto &r: right) {
                    TreeNode *root = new TreeNode(i); //要实现深拷贝，需要写在循环里
                    root->left = l;
                    root->right = r;
                    gen_trees.emplace_back(root);
                }
            }
        }
        return gen_trees;
    }

    int max_sum = 0;

    int Tree::maxSumBST(TreeNode *root) {
        maxSumBSTIsBSTRecur(root);
        return max_sum;
    }

    vector<int> Tree::maxSumBSTIsBSTRecur(TreeNode *root) { //max, min, isBST, treeSum
        if (root == nullptr) {
            return {-40001, 40001, 1, 0};
        }
        vector<int> left = maxSumBSTIsBSTRecur(root->left);
        vector<int> right = maxSumBSTIsBSTRecur(root->right);
        vector<int> res(4, 0);
        res[0] = max(max(left[0], right[0]), root->val);
        res[1] = min(min(left[1], right[1]), root->val);
        res[2] = left[2] && right[2] && (root->val > left[0]) && (root->val < right[1]);
        res[3] = left[3] + right[3] + root->val;

        if (res[2]) {
            max_sum = max(max_sum, res[3]);
        }
        return res;
    }

    int Tree::countHighestScoreNodes(vector<int> &parents) {
        vector<vector<int>> tree(parents.size(), vector<int>());
        for (int i = 0; i < parents.size(); i++) {
            int parent = parents[i];
            if (parent == -1) {
                continue;
            }
            tree[parent].emplace_back(i);
        }
        int max_score = INT_MIN;
        int max_res = -1;
        for (auto p: scores) {
            if (p.first > max_score) {
                max_score = p.first;
                max_res = p.second;
            }
        }
        return max_res;
    }

    int Tree::countHighestScoreNodes(int node) {
        if (tree[node].size() == 0) {
            return 0;
        }
        vector<int> node_cnts;
        for (auto child: tree[node]) {
            int node_cnt = countHighestScoreNodes(child);
            node_cnts.emplace_back(node_cnt);
        }
        int score = 1;
        int children_cnts = 0;
        for (auto cnt: node_cnts) {
            score *= cnt;
            children_cnts += cnt;
        }
        int parent_cnt = tree.size() - 1 - children_cnts;
        score *= max(parent_cnt, 1);
        scores[score]++;
        return children_cnts + 1;
    }

    int Tree::sumEvenGrandparent(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int res = sumEvenGrandparent(root->left);
        res += sumEvenGrandparent(root->right);
        if (root->val % 2 == 0) {
            if (root->left != nullptr) {
                if (root->left->left != nullptr) {
                    res += root->left->left->val;
                }
                if (root->left->right != nullptr) {
                    res += root->left->right->val;
                }
            }
            if (root->right != nullptr) {
                if (root->right->left != nullptr) {
                    res += root->right->left->val;
                }
                if (root->right->right != nullptr) {
                    res += root->right->right->val;
                }
            }
        }
        return res;
    }

    TreeNode *Tree::pruneTree(TreeNode *root) {
        bool head = pruneTreeRecur(root);
        return head ? nullptr : root;
    }

    bool Tree::pruneTreeRecur(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool left = pruneTreeRecur(root->left);
        bool right = pruneTreeRecur(root->right);
        if (left) {
            root->left = nullptr;
        }
        if (right) {
            root->right = nullptr;
        }
        return root->val == 0 && left && right;
    }

    bool Tree::isBalanced(TreeNode *root) {
        is_balanced = true;
        isBalancedRecur(root);
        return is_balanced;
    }

    int Tree::isBalancedRecur(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = isBalancedRecur(root->left);
        int right = isBalancedRecur(root->right);
        if (abs(left - right) > 1) {
            is_balanced = false;
        }
        return max(left, right) + 1;
    }

    bool Tree::isSubStructure(TreeNode *A, TreeNode *B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }
        return isSubStructureSameTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);

    }

    bool Tree::isSubStructureSameTree(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return isSubStructureSameTree(A->left, B->left) && isSubStructureSameTree(A->right, B->right);
    }

    TreeNode *Tree::mirrorTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode *left = mirrorTree(root->left);
        TreeNode *right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    bool Tree:: isSymmetric(TreeNode* root) {
        return !root || isSymmetric(root->left, root->right);
    }

    bool Tree:: isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }

        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    TreeNode* Tree::removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return root;
        }
        TreeNode* left = removeLeafNodes(root->left, target);
        TreeNode* right = removeLeafNodes(root->right, target);
        if (!left && !right && root->val == target) {
            return nullptr;
        }
        root->left = left;
        root->right = right;
        return root;
    }

    bool Tree::evaluateTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (root->val <= 1) {
            return (root->val == 1);
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return root->val == 2 ? (left || right) : (left && right);
    }

    int Tree::maxAncestorDiff(TreeNode* root) {
        maxAncestorDiffExtre(root);
        return res;
    }

    pair<int,int> Tree::maxAncestorDiffExtre(TreeNode* root) {
        if (!root) {
            return {1e5+1, -1};
        }
        auto left = maxAncestorDiffExtre(root->left);
        auto right = maxAncestorDiffExtre(root->right);
        int min_val = min(left.first, right.first);
        int max_val = max(left.second, right.second);
        res = min_val == 1e5+1 ? res : max(res, abs(root->val - min_val));
        res = max_val == -1 ? res : max(res, abs(root->val - max_val));
        return {min(min_val,root->val), max(max_val,root->val)};
    }

    TreeNode* Tree::sufficientSubset(TreeNode* root, int limit) {
        bool res = sufficientSubset(root, 0, limit);
        return res ? root : nullptr;
    }
    bool Tree::sufficientSubset(TreeNode* root, int sum, int limit) {
        if (!root) {
            return true;
        }
        sum += root->val; //debug 位置
        if (!root->left && !root->right) {
            //cout<<"del:"<<root->val<<sum <<endl;
            return (sum >= limit);
        }
        bool left = sufficientSubset(root->left, sum, limit);
        if (!left) {
            // cout<<"left:"<<root->val<<endl;
            root->left = nullptr;
        }
        bool right = sufficientSubset(root->right, sum, limit);
        if (!right) {
            //cout<<"right:"<<root->val<<endl;
            root->right = nullptr;
        }
        //sum -= root->val;
        //cout<<"end:"<<root->val<<!root->left<<!root->right<<endl;
        return (root->left || root->right); //debug truefalse反了
    }

    CBTInserter::CBTInserter(TreeNode *root) {
        this->root = root;
        nodes.emplace(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = nodes.front();
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
                if (node->left == nullptr || node->right == nullptr) {
                    return;
                }
                nodes.pop();
            }
        }
    }

    int CBTInserter::insert(int val) {
        TreeNode *node = new TreeNode(val);
        TreeNode *parent = nodes.front();
        if (parent->left == nullptr) {
            parent->left = node;
        } else {
            parent->right = node;
            nodes.pop();
        }
        nodes.emplace(node);
        return parent->val;
    }

    TreeNode *CBTInserter::get_root() {
        return this->root;
    }

}
