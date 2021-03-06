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
//    解决一个回溯问题，实际上就是一个决策树的遍历过程，站在回溯树的一个节点上，你只需要思考 3 个问题：
//    1、路径：也就是已经做出的选择。
//    2、选择列表：也就是你当前可以做的选择。
//    3、结束条件：也就是到达决策树底层，无法再做选择的条件。

//本质就是穷举所有解，而这些解呈现树形结构

//    result = []
//    def backtrack(路径, 选择列表):
//    if 满足结束条件:
//            result.add(路径)
//    return
//    for 选择 in 选择列表:
//            做选择
//            backtrack(路径, 选择列表)
//    撤销选择
    //[46] 全排列 m
    vector<vector<int>>res;
    vector<vector<int>>total;
    vector<int>path;
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

    //[offer2 110] 所有路径 //DFS
    //回溯算法的「做选择」和「撤销选择」在 for 循环里面，DFS在 for 循环外面 （否则DFS会漏掉记录起始点的遍历）
    //回溯算法关注树枝,DFS关注节点
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
    void allPathsSourceTarget(vector<vector<int>>& graph, int node);


};


#endif //CPP_BACKTRACKING_H
