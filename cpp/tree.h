//
// Created by Gabrielle Wang on 2022/4/20.
//

//https://labuladong.github.io/algo/1/7/
/* 二叉树遍历框架 */
/*
void traverse(TreeNode root) {
        // 前序遍历
        traverse(root.left)
        // 中序遍历
        traverse(root.right)
        // 后序遍历
        }
*/
/* 多叉树遍历框架 */
//void traverse(TreeNode root) {
//    if (root == null) return;
//    // 前序位置
//    for (TreeNode child : root.children) {
//        traverse(child);
//    }
//    // 后序位置
//}
//前序位置的代码在刚刚进入一个二叉树节点的时候执行；
//后序位置的代码在将要离开一个二叉树节点的时候执行；
//中序位置的代码在一个二叉树节点左子树都遍历完，即将开始遍历右子树的时候执行。
//根据题意，思考一个二叉树节点需要做什么，到底用什么遍历顺序就清楚了。
//中序位置主要用在 BST 场景中，你完全可以把 BST 的中序遍历认为是遍历有序数组

//前序位置的代码执行是自顶向下的，而后序位置的代码执行是自底向上的,意味着前序位置的代码只能从函数参数中获取父节点传递来的数据，而后序位置的代码不仅可以获取参数数据，还可以获取到子树通过函数返回值传递回来的数据
//一旦你发现题目和子树有关，那大概率要给函数设置合理的定义和返回值，在后序位置写代码了

//「分解问题」的思路，核心在于你要给递归函数一个合适的定义，然后用函数的定义来解释你的代码；如果你的逻辑成功自恰，那么说明你这个算法是正确的。

// 输入一棵二叉树的根节点，层序遍历这棵二叉树
/*
void levelTraverse(TreeNode root) {
    if (root == null) return;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    // 从上到下遍历二叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            // 将下一层节点放入队列
            if (cur.left != null) {
                q.offer(cur.left);
            }
            if (cur.right != null) {
                q.offer(cur.right);
            }
        }
    }
}
*/

/*
 * void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target)
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
 */

#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#ifndef CPP_TREE_H
#define CPP_TREE_H

#endif //CPP_TREE_H
using namespace std;
namespace tree {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Tree {
    public:
        int maxDepth(TreeNode *root);

        int diameter = 0;

        // transverse
        void preOrderNonRecur(TreeNode *node);

        // 需要背，写不对
        void inOrderNonRecur(TreeNode *node);

        // 需要背，写不对
        void postOrderNonRecur(TreeNode *node);

        // [543] 二叉树直径 easy
        int diameterOfBinaryTree(TreeNode *root);

        int depthOfBinaryTree(TreeNode *root);

        // [剑指 Offer 68 - II.] 二叉树的最近公共祖先 easy  //做了好几次还是不记得
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
        //第二次做，fine //3rd, 没问题
        TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q);
        TreeNode *lowestCommonAncestor3(TreeNode *root, TreeNode *p, TreeNode *q);

        // [剑指 Offer 34] 二叉树路径长等于某值 medium //对节点的操作的位置，体会纲领
        std::vector<std::vector<int>> paths;
        std::vector<int> path; //用公共变量
        std::vector<std::vector<int>> pathSum(TreeNode *root, int target);

        void pathSumRecur(TreeNode *root, int target);

        // [剑指 Offer 33] 二叉搜索树的后序遍历序列 m //终止条件是什么，验证依据是什么
        bool verifyPostorder(std::vector<int> &postorder);

        bool verifyPostorderRecur(std::vector<int> &postorder, int i, int j);

        // [剑指 Offer 07] 重建二叉树 m //注意边界条件，直接加个特殊判断最快
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

        TreeNode *buildTreeRecur(vector<int> &preorder, int i, int j, vector<int> &inorder, int s, int t);

        // [230] 二叉搜索树中第K小的元素 m //践行纲领 //函数参数携带的是父节点的信息，类似回溯；全局变量对全局生效，携带遍历路径上所有信息，类似路径与路程中的路程
        int seq = 0;
        int k_res = 0;

        int kthSmallest(TreeNode *root, int k);

        void kthSmallestRecur(TreeNode *root, int k);

        // [114] 二叉树展开为链表 m // 细节，二叉树指针变动的情况要考虑所有子节点和变动顺序
        void flatten(TreeNode *root);

        TreeNode *flattenRecur(TreeNode *root);

        // [116] 填充每个节点的下一个右侧节点指针 //递归的方法难想，要给函数设置合理的逻辑意义，像dp的思路
        TreeNode *connect(TreeNode *root);

        void connectRecur(TreeNode *node1, TreeNode *node2);

        // [654] 最大二叉树 easy //递归教在题目里，注意while 先写i++，容易忘
        TreeNode *constructMaximumBinaryTree(vector<int> &nums);

        TreeNode *constructMaximumBinaryTreeRecur(vector<int> &nums, int i, int j);

        int constructMaximumBinaryTreeFindMaxIdx(vector<int> &nums, int i, int j);

        // [652] 寻找重复子树 m //子树相关-后序保存子树信息，树相同-树的序列化，c++ 容器的用法 //第二次知道思路
        vector<TreeNode *> sub_roots;
        map<string, int> sub_trees;

        vector<TreeNode *> findDuplicateSubtrees(TreeNode *root);

        string findDuplicateSubtreesRecur(TreeNode *root);

        // [1038] 从二叉搜索树到更大和树 easy // 最开始想错了，bst的性质
        int sum = 0;

        TreeNode *bstToGst(TreeNode *root);

        // [450] 删除二叉搜索树中的节点 medium //二叉树框架的运用，返回值的含义理解？
        TreeNode *deleteNode(TreeNode *root, int key);

        // [95] 不同的二叉搜索树 II m //hard, 递归回溯，浅拷贝问题
        vector<TreeNode *> generateTrees(int n);

        vector<TreeNode *> generateTrees(int s, int t);

        // [1373] 二叉搜索子树的最大键值和 hard //后序需要多个子树信息，就用struct返回值
        int max_sum = 0;

        int maxSumBST(TreeNode *root);

        vector<int> maxSumBSTIsBSTRecur(TreeNode *root);

        //[124] //树模版，初始化max不对边界case
        int maxPathSum(TreeNode* root);
        int maxPathSumRecur(TreeNode* root);

        //[2049] 统计最高分的节点数目
        map<int, int> scores;
        vector<vector<int>> tree;

        int countHighestScoreNodes(vector<int> &parents);

        int countHighestScoreNodes(int node);

        // [1315] 祖父节点值为偶数的节点和 easy //dont panic, 遵循bt解题思路，节点需要做什么，前中后哪里
        int sumEvenGrandparent(TreeNode *root);

        // [剑指 Offer II 047] 二叉树剪枝 easy //注意考虑边界case+1
        TreeNode *pruneTree(TreeNode *root);

        bool pruneTreeRecur(TreeNode *root);

        //[剑指 Offer 55 - II] 平衡二叉树 easy //第二次做想复杂了
        bool isBalanced(TreeNode *root);

        bool is_balanced;

        int isBalancedRecur(TreeNode *root);

        // [offer 26] 树的子结构 //仔细审题，结构的定义，边界的定义 //不要考虑最简，先写对
        bool isSubStructure(TreeNode *A, TreeNode *B);

        bool isSubStructureSameTree(TreeNode *A, TreeNode *B);

        //[offer 27] 镜像二叉树 easy
        TreeNode *mirrorTree(TreeNode *root);

        //[offer 28] 对称二叉树判断 easy //自己没做出来 //第二次做很简单
        bool isSymmetric(TreeNode *root);

        bool isSymmetric(TreeNode *left, TreeNode *right);

        //[1325] 删除target值的叶子结点 e //
        TreeNode* removeLeafNodes(TreeNode* root, int target);

        //[2331] easy // demo
        bool evaluateTree(TreeNode* root);

        //[1026] 节点最大diff e //demo
        int maxAncestorDiff(TreeNode* root);
        int res = 0;
        pair<int,int> maxAncestorDiffExtre(TreeNode* root);

        //[1080] 根据路径和删除节点 m //题没读懂，思路看了答案，转化问题到判断条件上
        TreeNode* sufficientSubset(TreeNode* root, int limit) ;
        bool sufficientSubset(TreeNode* root, int sum, int limit);



    };
    class CBTInserter {
    public:
        TreeNode *root;
        queue<TreeNode *> nodes;

        // 1
        // 2 3
        CBTInserter(TreeNode *root);

        int insert(int val);

        TreeNode *get_root();

    };
}