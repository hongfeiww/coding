import java.util.*;

//
//回溯算法是一种通过不断尝试 ，搜索一个问题的一个解或者 所有解 的方法。
//在求解的过程中，如果继续求解不能得到题目要求的结果，就需要 回退 到上一步尝试新的求解路径。
//回溯算法的核心思想是：在一棵 隐式的树（看不见的树） 上进行一次深度优先遍历。



//问「一个问题 所有的 解」一般考虑使用回溯算法。因此回溯算法也叫「暴力搜索」，
// 但不同于最粗暴的多个 for 循环，回溯算法是有方向的遍历。

//理解「回溯算法」的一个重要技巧是 在程序中打印状态变量进行观察，一步一步看到变量的变化。

public class BackTracing {

    //DFS
    /*
    result = []
    def backtrack(路径, 选择列表):
            if 满足结束条件:
            result.add(路径)
            return
            for 选择 in 选择列表:
                做选择
                backtrack(路径, 选择列表)
                撤销选择
    */



    // [1302. 层数最深叶子节点的和] medium
    // 目的是找到最深层：层次 -> BFS； 最深 -> DFS
    //BFS DFS
    public int deepestLeavesSum(TreeNode root) {
        return 0;
    }

    // [剑指 Offer II 079. 所有子集] medium-> easy
    //简单递归
    public List<List<Integer>> subsets(int[] nums) {
        System.out.println("num: " + Arrays.toString(nums));
        if (nums.length == 1) { //[],[x]
            List<List<Integer>> res = new ArrayList<List<Integer>>();
            res.add(new ArrayList<>(Arrays.asList(nums[0])));
            res.add(new ArrayList<>());
            return res;
        }
        List<List<Integer>> lastOne = subsets(Arrays.copyOfRange(nums, 0, nums.length - 1));
        List<List<Integer>> newOne = new ArrayList<List<Integer>>(lastOne);
        for (List<Integer> l : lastOne) {
            List<Integer> newl = new ArrayList<>(l);
            newl.add(nums[nums.length - 1]);
            newOne.add(newl);
        }

        System.out.println("res: " + lastOne);
        return newOne;
    }

    List<List<Integer>> ans =new ArrayList<>();
    public List<List<Integer>> subsets2(int[] nums) {
        HashSet<Integer>path = new HashSet<Integer>();
        for(int n:nums){
            path.add(n);
        }

        subsetsDFS(nums, new ArrayList<Integer>(),path);
        return ans;
    }

    public void subsetsDFS(int[] nums, List<Integer>res, HashSet<Integer> path) {
        if (path.size()==0){
            ans.add(res);
            return;
        }

        for (int i:path){
            HashSet<Integer> newPath =new HashSet<Integer>(path);
            newPath.remove(i);
            res.add(i);
            subsetsDFS(nums,res,newPath);
            res.remove(res.size()-1);
            subsetsDFS(nums,res,newPath);
        }
    }

    //[所有排列]
    List<List<Integer>> res = new ArrayList<>();
    HashMap<Integer,Boolean> visited =new HashMap<>();
    public List<List<Integer>> permute(int[] nums) {
        for (int num : nums) {
            visited.put(num, false);
        }
        permuteDFS(nums,new ArrayList<Integer>());
        return res;
    }

    public void permuteDFS(int[] nums,ArrayList<Integer> ans) {
        System.out.println("ans: "+ans);
        if (ans.size()==nums.length){
            res.add(new ArrayList<>(ans));
        }
        for (int num : nums) {
            if (!visited.get(num)){
                ans.add(num);
                visited.put(num, true);
                permuteDFS(nums,ans);
                ans.remove(ans.size()-1);
                visited.put(num, false);
            }
        }
    }

    /* 主函数，输入一组不重复的数字，返回它们的全排列 */
    List<List<Integer>> permute2(int[] nums) {
        // 记录「路径」
        LinkedList<Integer> track = new LinkedList<>();
        permute2backtrack(nums, track);
        return res;
    }

    // 路径：记录在 track 中
// 选择列表：nums 中不存在于 track 的那些元素
// 结束条件：nums 中的元素全都在 track 中出现
    void permute2backtrack(int[] nums, LinkedList<Integer> track) {
        // 触发结束条件
        System.out.println("res: "+track);
        if (track.size() == nums.length) {
            res.add(new LinkedList(track));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // 排除不合法的选择
            if (track.contains(nums[i]))
                continue;
            // 做选择
            track.add(nums[i]);
            // 进入下一层决策树
            System.out.println("choose: "+nums[i]);
            permute2backtrack(nums, track);
            // 取消选择
            track.removeLast();
        }
    }

}
