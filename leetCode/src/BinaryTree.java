import java.util.LinkedList;

public class BinaryTree {

    private LinkedList<TreeNode> res;

    public BinaryTree() {
        res = new LinkedList<>();

    }

    public LinkedList<TreeNode> getRes() {
        return res;
    }

    public void setRes(LinkedList<TreeNode> res) {
        this.res = res;
    }

    public void preOrderTraversal(TreeNode root) {
        if (root == null) { //base case!!
            return;
        }
        res.add(root);
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }


    public TreeNode GetMaxTree (int[] nums) {
        return MaxTreeRecur (nums,0,nums.length-1);
    }

    public TreeNode MaxTreeRecur (int[] nums,int i,int j) {
        if (i>j){
            return null;
        }
        if (i==j){
            return new TreeNode(nums[i]);
        }
        int idx = findMax(nums,i,j);
        TreeNode root= new TreeNode(nums[idx]);
        root.left=MaxTreeRecur(nums,i,idx-1);
        root.right=MaxTreeRecur(nums,idx+1,j);
        return root;
    }

    public int findMax (int[] nums,int i,int j) {
        int maxIdx=i;
        for (int t=i;t<=j;t++){
            if (nums[t]>nums[maxIdx]){
                maxIdx=t;
            }
        }
        return maxIdx;
    }
}
