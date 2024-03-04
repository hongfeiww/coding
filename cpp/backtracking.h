//
// Created by Gabrielle Wang on 2022/6/20.
//

#ifndef CPP_BACKTRACKING_H
#define CPP_BACKTRACKING_H
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

class backtracking {
public:
//    解决一个回溯问题，实际上就是一个决策树的遍历过程，站在回溯树的一个节点上，你只需要思考 3 个问题：
//    1、路径：也就是已经做出的选择。
//    2、选择列表：也就是你当前可以做的选择。
//    3、结束条件：也就是到达决策树底层，无法再做选择的条件。

//本质就是穷举所有解，而这些解呈现树形结构,做题画出来决策树就好了

//    result = []
//    def backtrack(路径, 选择列表):
//    if 满足结束条件:
//            result.add(路径)
//    return
//    for 选择 in 选择列表:
//            做选择
//            backtrack(路径, 选择列表)
//    撤销选择

    //[52][51] N皇后，需要记录做选择的限制条件，斜线
    int res_int = 0;
    int totalNQueens(int n);
    void totalNQueens(int n, int row, set<int> cols, set<int> left, set<int> right);

    //[46] 全排列 m
    vector<vector<int>>res;
    vector<vector<int>>total;
    vector<int>path;
    vector<int>subset;
    vector<vector<int>> permute(vector<int>& nums);
    void permute(vector<int>& nums,vector<bool>& visited);

    //[47] 全排列2 m
    //对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」= 限制填入顺序
    vector<vector<int>> permuteUnique(vector<int>& nums);
    void permuteUnique(vector<int>& nums, vector<bool>& visited);

    //[77] 组合 m //和排列相似
    vector<vector<int>> combine(int n, int k);
    void combineBT(int n, int k);

    //[78] 子集 //和组合相似，组合是子集的一种情况
    vector<vector<int>> subsets(vector<int>& nums);
    void subsets(vector<int>& nums, int pre);

    //[90] 子集2 //存在重复情况的处理
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    void subsetsWithDup(vector<int>& nums, int pre);

    //[39] 组合总和
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void combinationSum(vector<int>& candidates, int left, int idx);

    //[17] 电话号码组合 m// 简单模版
    vector<string> letterCombinations(string digits);
    void letterCombinations(string digits, int idx, string path);

    //[offer2 110] 所有路径 //DFS
    //回溯算法的「做选择」和「撤销选择」在 for 循环里面，DFS在 for 循环外面 （否则DFS会漏掉记录起始点的遍历）
    //回溯算法关注树枝,DFS关注节点
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
    void allPathsSourceTarget(vector<vector<int>>& graph, int node);

    //[698] 划分为k个相等子集 //想不出来就回溯，暴力=回溯 //time exceed -> prune，这个prune方法没想到
    bool canPartitionKSubsetsRecur(vector<int>& nums, vector<int>& sums, int pos, int sum);
    bool canPartitionKSubsets(vector<int>& nums, int k);

    //[offer2 086]分割palindrome string //回溯是分支视角，一开始的执行逻辑角度不对，以为是累积的 // 迭代计算回文串
    //实际上拆解了，无法同时回溯+判断pali。先pali，然后选择为所有的pali
    //选择这里可以不是for，可以for加条件
    vector<vector<string>>res_strs;
    vector<string>path_str;
    vector<vector<string>> partition(string s);
    void partition(string s, vector<vector<bool>> &is_palindrome, int pos);

    int findTargetSumWays(vector<int>& nums, int target);
    int res_cnt = 0;
    void findTargetSumWaysBT(vector<int>& nums, int target ,int pos);

    //[offer2 085] 生成匹配括号 easy //自己实现的，简单模版
    string str = "";
    vector<string> generateParenthesis(int n);
    void generateParenthesis(int n, int left_cnt, int right_cnt);

    //[offer2 087] 复原IP m //回溯模版//读题看漏了条件，string的substr一直debug
    vector<string> restoreIpAddresses(string s);
    void restoreIpAddresses(string s, int pos, int cut);

    ///GREEDY
    //[2375] 根据模式串构造最小数字 //贪心就可以，注意边界case
    string smallestNumber(string pattern);
    // [630] 课程表3 h  //贪心的方法想不到,后退贪心
    int scheduleCourse(vector<vector<int>>& courses);
    //[1326] 花园浇灌最少水龙头数目 m //贪心方法想不到，得用感觉理解 //dp的办法列的转化不对
    int minTaps(int n, vector<int>& ranges);
    //[1144] 递减元素使得数组呈锯齿状 m //贪心没想出来 // dp问题没想对，因为题目只递减没get
    int movesToMakeZigzag(vector<int>& nums);
    //[1605] 给定行列sum求可行矩阵 e //想不出来 //子问题，进行贪心之后子问题不变
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum);
    //[135] 分发糖果 h //代码和思路简单，我记得我做过，所以第二次会写
    int candy(vector<int>& ratings) ;


};


#endif //CPP_BACKTRACKING_H
