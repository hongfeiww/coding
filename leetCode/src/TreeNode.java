

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

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

//根据题意，思考一个二叉树节点需要做什么，到底用什么遍历顺序就清楚了。

public class TreeNode {
    TreeNode left;
    TreeNode right;
    int val;
    TreeNode next;

    public TreeNode getLeft() {
        return left;
    }

    public TreeNode getRight() {
        return right;
    }

    public int getVal() {
        return val;
    }

    public TreeNode() {

    }

    public void setLeft(TreeNode left) {
        this.left = left;
    }

    public void setRight(TreeNode right) {
        this.right = right;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public TreeNode(int val) {
        setVal(val);
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        setVal(val);
        setLeft(left);
        setRight(right);
    }

    public TreeNode(TreeNode root) {
        setVal(root.val);
        setLeft(root.left);
        setRight(root.right);
    }

    public void traverse(TreeNode root) {

    }
    static class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    };
    // N 叉树的前序遍历
    List<Integer> res = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        preorderDFS(root);
        return res;
    }

    public void preorderDFS(Node root) {
        if (root==null) {
            return;
        }
        res.add(root.val);
        for (Node node:root.children){
            preorderDFS(node);
        }
    }

    // [226. 翻转二叉树] easy
    // 前序遍历 后序遍历 pre-order in-order post-order traversal
    // 二叉树题目的一个难点就是，如何把题目的要求细化成每个节点需要做的事情。
    // 先搞清楚当前 root 节点该做什么，然后根据函数定义递归调用子节点
    // 对称递归
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode tmp = root.right;
        root.right = root.left;
        root.left = tmp;
        root.right = invertTree(root.right);
        root.left = invertTree(root.left);
        return root;
    }

    //[116. 填充每个节点的下一个右侧节点指针] medium
    //BFS or traversal TODO
    //层次遍历基于广度优先搜索，它与广度优先搜索的不同之处在于，广度优先搜索每次只会取出一个节点来拓展，而层次遍历会每次将队列中的所有元素都拿出来拓展
    //二叉树层次相关：BFS
    public TreeNode connect(TreeNode root) {
        if (root == null) {
            return null;
        }
        LinkedList<TreeNode> queue = new LinkedList<>(); //queue addLast+pop

        root.next = null;
        if (root.left == null) {
            return root;
        }
        queue.addLast(root.left); //第一个节点判断有点麻烦
        queue.addLast(root.right);
        queue.addLast(null);
        while (!queue.isEmpty()) {
            TreeNode node = queue.pop();
            if (node == null) { //debug：对于null的处理，root为null，root.left panic
                continue;
            }
            if (node.left != null) {
                queue.addLast(node.left);
                queue.addLast(node.right);
            }
            node.next = queue.peek(); //没有使用层次遍历的BFS，每次只弹出一个，而不是所有（一层）
            if (queue.peek() == null) {
                queue.addLast(null);
            }
        }
        return root;
    }

    // [114. 二叉树展开为链表] medium
    // 简单版 = pre-order traversal
    // 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？post-order traversal
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        flatten(root.left);
        flatten(root.right);
        TreeNode left = root.left;
        TreeNode right = root.right;
        if (left == null) {
            return;
        }
        if (right != null) {
            while (left.right != null) { //暴力找到树叶，有时候直接考虑暴力方法
                left = left.right;
            }
            left.right = right;
        }

        root.right = root.left;
        root.left = null;
    }

    // [654. 最大二叉树] medium
    // 暴力找max值 + pre-order
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return null;
    }

    // [105. 从前序与中序遍历序列构造二叉树] medium
    // 把题目的要求细化，搞清楚根节点应该做什么，
    // 然后剩下的事情抛给前/中/后序的遍历框架就行了，千万不要跳进递归的细节里
    // [106. 从中序与后序遍历序列构造二叉树] medium
    // 同上
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTreeRecur(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    public TreeNode buildTreeRecur(int[] inorder, int inS, int inE, int[] postorder, int postS, int postE) {
        if (inE < inS) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[postE]);
        int rootIdx = getRootIdx(inorder, postorder[postE]);
        int rightSize = inE - rootIdx;
        root.left = buildTreeRecur(inorder, inS, rootIdx - 1, postorder, postS, postE - rightSize - 1);
        root.right = buildTreeRecur(inorder, rootIdx + 1, inE, postorder, postE - rightSize, postE - 1);
        return root;
    }

    public int getRootIdx(int[] inorder, int val) {
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // [652. 寻找重复的子树] medium
    // 用什么遍历方式
    // 先不要考虑复杂度，能解出来
    // 我如何才能知道以自己为根的二叉树长啥样？
    //其实看到这个问题，就可以判断本题要使用「后序遍历」框架来解决

    // [230. 二叉搜索树中第K小的元素]
    // BST的性质：inorder is sorted
    int index = 0;
    int rres = 0;

    public int kthSmallest(TreeNode root, int k) {
        kthSmallestRecur(root, k);
        return rres;
    }

    public void kthSmallestRecur(TreeNode root, int k) {
        if (root == null) {
            return;
        }
        kthSmallestRecur(root.left, k);
        index++;
        if (index == k) {
            rres = root.val;
            return;
        }
        kthSmallestRecur(root.right, k);
    }

    // [538. 把二叉搜索树转换为累加树]
    // 利用inorder的性质，inorder asc/ reverse inorder desc
    // bst: 要找到所有比root大/小：inorder
    int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        convertBSTRecur(root);
        return root;
    }

    public void convertBSTRecur(TreeNode root) {
        if (root == null) {
            return;
        }
        convertBSTRecur(root.right);
        sum += root.val;
        root.val = sum;

        convertBSTRecur(root.left);
    }

    // [98. 验证二叉搜索树] medium
    // 增加递归的传参信息
    // 我们通过使用辅助函数，增加函数参数列表，在参数中携带额外信息，将这种约束传递给子树的所有节点，这也是二叉树算法的一个小技巧吧
    // solution2： inorder 保留前一个node的信息
    // TODO: 递归中有无返回值的不同情况的写法
    TreeNode pre = null;

    public boolean isValidBST(TreeNode root) {
        return isValidBSTRecur(root);
    }

    public boolean isValidBSTRecur(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!isValidBSTRecur(root.left)) {
            return false;
        }
        if (pre != null) {
            if (root.val <= pre.val) {
                return false;
            }
        }
        pre = root;
        return isValidBSTRecur(root.right);

    }

    //BST 遍历框架
    /*
    void BST(TreeNode root, int target) {
        if (root.val == target)
            // 找到目标，做点什么
            if (root.val < target)
                BST(root.right, target);
        if (root.val > target)
            BST(root.left, target);
    }
    */

    // [701. 二叉搜索树中的插入操作] medium
    // 二叉树查找 easy preorder框架
    // 有返回值的递归写法
    // 题目抽象：bst的遍历搜索
    public TreeNode insertIntoBST(TreeNode root, int val) {
        return insertIntoBSTRecur(root, val);
    }

    public TreeNode insertIntoBSTRecur(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (val < root.val) {
            root.left = insertIntoBSTRecur(root.left, val);
        } else {
            root.right = insertIntoBSTRecur(root.right, val);
        }
        return root;
    }

    // [450. 删除二叉搜索树中的节点] medium
    // 递归写法：
    // 返回原来的树： root.left = recur();root.right = recur();return root;
    // 返回查找结果： return recur(l);return recur(r)
    // 巧妙删除节点的方式：其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点。

    public TreeNode deleteNode(TreeNode root, int key) {
        return deleteNodeSearch(root, key);
    }

    public TreeNode deleteNodeSearch(TreeNode root, int key) {
        if (root == null) {
            return root;
        }
        if (key == root.val) {
            if (root.left == null) {
                return root.right;
            }
            if (root.right == null) {
                return root.left;
            }
            int val = findInorderPreNode(root).val;
            root.left = deleteNodeSearch(root.left, val); //复杂方式，需要在子树中删除新的根结点节点
            root.val = val; //转移节点使用了值copy的方法
        } else if (key < root.val) {
            root.left = deleteNodeSearch(root.left, key);
        } else {
            root.right = deleteNodeSearch(root.right, key);
        }
        return root;
    }

    public TreeNode findInorderPreNode(TreeNode root) {
        TreeNode res = root.left;
        while (res.right != null) {
            res = res.right;
        }
        return res;
    }

    // 找出二叉树中某个结点的所有祖先结点

    public boolean FindAllAncestors(TreeNode node, TreeNode target) {
        if (node == null) {
            return false;
        }
        if (node == target) {
            return true;
        }
        return FindAllAncestors(node.left, target) || FindAllAncestors(node.right, target);
    }

    // [112. 路径总和] easy
    // 结合边界case确定递归终点
    //空树是true还是false？ 递归终点null + 叶子结点
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return false;
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isSymmetricDFS(root.left, root.right);
    }

    //[对称二叉树]
    //两个变量的递归

    public boolean isSymmetricDFS(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        if (left == null || right == null) {
            return false;
        }
        return left.val == right.val &&
                isSymmetricDFS(left.left, right.right) &&
                isSymmetricDFS(left.right, right.left);
    }


     // [求根到叶子节点数字之和]
    //dfs和dp的区别，思路的不同
    //树-> 搜索，dfs

    //[1008. 前序遍历构造二叉搜索树]
    //cut 边界条件构造 //TODO
    public TreeNode bstFromPreorder(int[] preorder) {
        return bstFromPreorderDFS(preorder,0,preorder.length-1);
    }

    public TreeNode bstFromPreorderDFS(int[] preorder,int left,int right) {
        if (left>right){ //DEBUG
            return null;
        }
        int cut=bstFromPreorderFindRight(preorder,left,right);

        TreeNode res = new TreeNode(preorder[left]);
        System.out.println("cut: "+left+cut+right);
        res.left=bstFromPreorderDFS(preorder,left+1,cut-1);
        res.right=bstFromPreorderDFS(preorder,cut,right);
        return res;
    }

    public int bstFromPreorderFindRight(int[] preorder,int left,int right) {
        for (int i=left;i<=right;i++){
            if (preorder[i]>preorder[left]){
                return i;
            }
        }
        return right+1; //DEBUG
    }

    //[103. 二叉树的锯齿形层序遍历]


    //剑指 Offer 37. 序列化二叉树（层序遍历）
    // 想到不同步伐的可以使用双栈 -> 双/多指针


    //[剑指 Offer 26. 树的子结构] medium TODO
    // 复杂递归

//    public boolean isSubStructure(TreeNode A, TreeNode B) {
//
//    }
    //[剑指 Offer 33. 二叉搜索树的后序遍历序列]TODO
    //


}

