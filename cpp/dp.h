//
// Created by Gabrielle Wang on 2022/4/21.
//

#ifndef CPP_DP_H
#define CPP_DP_H
#include <vector>
#include <string>
#include "tree.h"
namespace dp {
    //动态规划问题的一般形式就是求最值
    //具备「最优子结构」，是否能够通过子问题的最值得到原问题的最值
    class dp {
    public:
        // [264] 丑数 II medium //是自己想不出来的那种题 //dp
        int nthUglyNumber(int n);

        // [剑指 Offer 47] 礼物的最大价值
        int maxValue(std::vector<std::vector<int>>& grid);
        // [剑指 Offer 46] 把数字翻译成字符串 //dp简单，更像是细节题
        int translateNum(int num);
        // [96] 不同的二叉搜索树 m //没想出来用dp，利用bst的性质
        int numTrees(int n);
        // [198] rob1
        int rob(std::vector<int>& nums);
        // [337] rob3 //dp里用map，可以get nullkey
        int rob(tree::TreeNode* root);
        vector<int> robDP(tree::TreeNode* root);
        // [LCP34] 二叉树染色 // 树dp直接是压缩的转移方程，有k参数时定义好转移方程的含义，不一定等于最终结果
        int maxValue(tree::TreeNode* root, int k);
        vector<int> maxValueRecur(tree::TreeNode* root, int k);
        // [offer 19] regex matching //做好几次都做不对
        bool isMatch(string s, string p);
        //[offer 60] n个骰子点数 // 看到提示了/ //dp的循环边界，细节
        vector<double> dicesProbability(int n);
        //[5] 最长回文子串 m //debug才做对 //len = j - i + 1
        string longestPalindrome(string s);
        //[55] jump game //dp 剪枝不然tle //greed
        bool canJump(vector<int>& nums);
        bool canJump(vector<int>& nums, int greed);
        //[44] regex e //dp, 有个复杂情况转移方程想少情况了
        bool isMatch2(string s, string p);
        //[174] 地下城游戏 h //逆向dp消除一个因子的影响，没想到
        int calculateMinimumHP(vector <vector<int>> &dungeon);
        //[offer 2.102] 加减的目标和 //背包问题但是我的思路不同，tle了需要简化
        int findTargetSumWays(vector<int>& nums, int target);
        //[72] 编辑距离 h //做过好几次了记住了，dp方程推理难
        int minDistance(string word1, string word2);
        int minimumDeletions(string s);
        //[1638] 统计只差一个字符的子串数量 m// 思路没想出来，拆解问题就像merge sort一样，拆成的小问题是已知问题
        int countSubstrings(string s, string t);
        //[1626] 无矛盾最佳球队 m //思路想出来了/ 实现上：cmp的写法；同时sort两个vector
        int bestTeamScore(vector<int>& scores, vector<int>& ages);
        //[1147] 段式回文 h //看到双指针之后思路get简单，但是实现很复杂写不出来，字符串内sub的复杂比较可以拷贝出来单独比较
        int longestDecomposition(string text);
        //[343] 整数拆分 m //剪绳子问题，思路记不住，一直觉得哪里怪怪的
        int integerBreak(int n);
        //[offer2 091] painting the house easy //思路和实现都简单
        int minCost(vector<vector<int>>& costs);
        //[offer2 098] path cnt easy //思路和实现都简单
        int uniquePaths(int m, int n);
        //[1043] 分割数组得到最大和 m //没想出来，是一种类型，以末尾为结尾不断延长
        int maxSumAfterPartitioning(vector<int> &arr, int k);


    };
}




#endif //CPP_DP_H
